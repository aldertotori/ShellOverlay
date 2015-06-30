// PathUtils.h: interface for the CPathUtils class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PATHUTILS_H__76517151_F65F_4D4C_97E0_D9239068C71D__INCLUDED_)
#define AFX_PATHUTILS_H__76517151_F65F_4D4C_97E0_D9239068C71D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>

class CStringBufA
{
public:
	CStringBufA(size_t len) : m_buf(NULL)
	{
		m_len = len;
		m_buf = (char*)CoTaskMemAlloc(len);
	}
	CStringBufA(char* buf) : m_buf(NULL)
	{
		m_len = strlen(buf) + 2;
		if(m_len)
		{
			//m_buf = new TCHAR[m_len];
			m_buf = (char*)CoTaskMemAlloc(sizeof(char) * m_len);
			if(m_buf)
				strcpy(m_buf,buf);
		}
	}
	virtual ~CStringBufA()
	{
		if(m_len && m_buf)			
			CoTaskMemFree(m_buf);
		m_buf = NULL;
	}
	void realloc(size_t len)
	{
		if(m_buf) CoTaskMemFree(m_buf);
		m_len = len;
		m_buf = (char*)CoTaskMemAlloc(len);
	}
	operator LPSTR() 
	{
		return(m_buf);
	}
	operator LPTSTR*()
	{
		return &m_buf;
	}
	operator LPCSTR()
	{
		return(m_buf);
	};
private:
	char*	m_buf;
	size_t	m_len;
};

class CStringBufW
{
public:
	CStringBufW(size_t len) : m_buf(NULL)
	{
		m_len = len;
		m_buf = (WCHAR*)CoTaskMemAlloc(sizeof(WCHAR) * len);
	}
	CStringBufW(WCHAR* buf) : m_buf(NULL)
	{
		m_len = wcslen(buf) + 2*sizeof(WCHAR);
		if(m_len)
		{
			//m_buf = new TCHAR[m_len];
			m_buf = (WCHAR*)CoTaskMemAlloc(sizeof(WCHAR) * m_len);
			if(m_buf)
				wcscpy(m_buf,buf);
		}
	}
	virtual ~CStringBufW()
	{
		if(m_len && m_buf)			
			CoTaskMemFree(m_buf);
		m_buf = NULL;
	}
	void realloc(size_t len)
	{
		if(m_buf) CoTaskMemFree(m_buf);
		m_len = len;
		m_buf = (WCHAR*)CoTaskMemAlloc(sizeof(WCHAR) * len);
	}
	operator LPWSTR() 
	{
		return(m_buf);
	}
	operator LPWSTR*() 
	{
		return(&m_buf);
	}
	operator LPCWSTR()
	{
		return(m_buf);
	};
private:
	WCHAR*	m_buf;
	size_t	m_len;
};

#if defined(_UNICODE) || defined(UNICODE)
#defome CStringBuf CStringBufW 
#else
#define CStringBuf CStringBufA 
#endif


enum FileTime_State
{
	FileTime_Equ,
	FileTime_Later,
	FileTime_Earlier,
	FileTime_OneNotExit,
	FileTime_TwoNotExit
};

class CPathUtils  
{
public:
	CPathUtils();
	virtual ~CPathUtils();
public:
	static std::string GetLongPathname(const std::string& path);
	static FileTime_State CompareFileTime(LPTSTR szFileName1,LPTSTR szFileName2);
};

#endif // !defined(AFX_PATHUTILS_H__76517151_F65F_4D4C_97E0_D9239068C71D__INCLUDED_)
