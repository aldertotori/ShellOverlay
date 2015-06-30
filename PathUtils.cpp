// PathUtils.cpp: implementation of the CPathUtils class.
//
//////////////////////////////////////////////////////////////////////
#include "StdAfx.h"
#include "PathUtils.h"

#pragma comment(lib,"shlwapi.lib")

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPathUtils::CPathUtils()
{
}

CPathUtils::~CPathUtils()
{
}

static FileTime_State CompareFileTime(LPTSTR szFileName1,LPTSTR szFileName2)
{
	FILETIME		ModifyTime1,ModifyTime2;
	LARGE_INTEGER	Time1,Time2;
	HANDLE	  hFile = CreateFile(szFileName1,
		GENERIC_READ,
		FILE_SHARE_READ|FILE_SHARE_WRITE,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if(hFile)
	{
		GetFileTime(hFile,NULL,NULL,&ModifyTime1);
		CloseHandle(hFile);
	}
	else
	{
		return FileTime_OneNotExit;
	}
	hFile = CreateFile(szFileName2,
		GENERIC_READ,
		FILE_SHARE_READ|FILE_SHARE_WRITE,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if(hFile)
	{
		GetFileTime(hFile,NULL,NULL,&ModifyTime2);
		CloseHandle(hFile);
	}
	else
	{
		return FileTime_TwoNotExit;
	}
	
	Time1.u.HighPart = ModifyTime1.dwHighDateTime;
	Time1.u.LowPart  = ModifyTime1.dwLowDateTime;
	Time2.u.HighPart = ModifyTime2.dwHighDateTime;
	Time2.u.HighPart = ModifyTime2.dwLowDateTime;
	if(Time1.QuadPart == Time2.QuadPart)
		return FileTime_Equ;
	else if(Time1.QuadPart < Time2.QuadPart)
		return FileTime_Earlier;
	else
		return FileTime_Later;
}

std::string CPathUtils::GetLongPathname(const std::string& path)
{
    if (path.empty())
        return path;
    TCHAR pathbufcanonicalized[MAX_PATH] = { 0 }; // MAX_PATH ok.
    DWORD ret = 0;
	std::string sRet = path;
    if (!PathIsURL(path.c_str()) && PathIsRelative(path.c_str()))
    {
        ret = GetFullPathName(path.c_str(), 0, NULL, NULL);
        if (ret)
        {
            CStringBuf pathbuf(ret+1);
            if ((ret = GetFullPathName(path.c_str(), ret, pathbuf, NULL))!=0)
            {
                sRet = std::string(pathbuf, ret);
            }
        }
    }
    else if (PathCanonicalize(pathbufcanonicalized, path.c_str()))
    {
        ret = ::GetLongPathName(pathbufcanonicalized, NULL, 0);
        if (ret == 0)
            return path;
        CStringBuf pathbuf(ret+2);
        ret = ::GetLongPathName(pathbufcanonicalized, pathbuf, ret+1);
        // GetFullPathName() sometimes returns the full path with the wrong
        // case. This is not a problem on Windows since its filesystem is
        // case-insensitive. But for SVN that's a problem if the wrong case
        // is inside a working copy: the svn wc database is case sensitive.
        // To fix the casing of the path, we use a trick:
        // convert the path to its short form, then back to its long form.
        // That will fix the wrong casing of the path.
        int shortret = ::GetShortPathName(pathbuf, NULL, 0);
        if (shortret)
        {
            CStringBuf shortpath(shortret+2);
            if (::GetShortPathName(pathbuf, shortpath, shortret+1))
            {
                int ret2 = ::GetLongPathName(shortpath, pathbuf, ret+1);
                if (ret2)
                    sRet = std::string(pathbuf);
            }
        }
    }
    else
    {
        ret = ::GetLongPathName(path.c_str(), NULL, 0);
        if (ret == 0)
            return path;
        CStringBuf pathbuf(ret+2);
        ret = ::GetLongPathName(path.c_str(), pathbuf, ret+1);
        sRet = std::string(pathbuf, ret);
        // fix the wrong casing of the path. See above for details.
        int shortret = ::GetShortPathName(pathbuf, NULL, 0);
        if (shortret)
        {
            CStringBuf shortpath(shortret+2);
            if (::GetShortPathName(pathbuf, shortpath, shortret+1))
            {
                int ret2 = ::GetLongPathName(shortpath, pathbuf, ret+1);
                if (ret2)
                    sRet = std::string(pathbuf);
            }
        }
    }
    if (ret == 0)
        return path;
    return sRet;
}
