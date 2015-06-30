// VSSMgr.h: interface for the CVSSMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VSSMGR_H__3DF2EC24_2AD8_4BF8_AE2E_E9AD8B0BA4D0__INCLUDED_)
#define AFX_VSSMGR_H__3DF2EC24_2AD8_4BF8_AE2E_E9AD8B0BA4D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#import "C:\Program Files\Microsoft Visual SourceSafe\ssapi.dll" no_namespace

#include "VSSApi.h"
#include "SRComHelper.h"

#include <vector>

class CVSSMgr  
{
public:
	CVSSMgr();
	virtual ~CVSSMgr();

	BOOL OpenDatabase(BSTR User = CComBSTR(""),BSTR Password = CComBSTR(""),BSTR srcIniFile = NULL);
	VOID Close();
	BOOL IsProjectExits(BSTR ProjectName);
	BOOL GetDefaultDatabase(LPWSTR FilePathBuf,IN OUT PULONG BufLen);
	HRESULT CheckIn(BSTR VSSPath,std::vector<BSTR*> &filesToCheckin);
	HRESULT Checkout(BSTR curDir,BSTR VSSPath);
	static BOOL IsVssInstalled(); 
	static BOOL FileExits(LPWSTR fileName);
#if !defined(_UNICODE) && !defined(UNICODE)
	static BOOL FileExits(LPSTR fileName);
#endif
private:
	
	CSRComHelper	*m_database;
	CSRComHelper	*m_vssitem;
	BOOL			m_b_opened;
	BOOL			m_b_connected;
};

#endif // !defined(AFX_VSSMGR_H__3DF2EC24_2AD8_4BF8_AE2E_E9AD8B0BA4D0__INCLUDED_)
