// VSSMgr.cpp: implementation of the CVSSMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "VSSMgr.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// Creating a SS database connection is as follows
//
// IVSSDatabasePtr mp_vssDatabase;
// mp_vssDatabase.CreateInstance(__uuidof(VSSDatabase);
// mp_vssDatabase->Open(psz_VSSini, psz_User, psz_Password);

/*
 // Downloading an Old Version of an Item

IVSSItemPtr vss_oldItem;
if (vss_item->get_Version(_variant_t(l_oldVersionNumber), 
&vss_oldItem) == S_OK)
{
// Download to the working directory
CComBSTR bstr_localSpec;
vss_item->get_LocalSpec(&bstr_localSpec);
vss_oldItem->Get(&bstr_localSpec, VSSFLAG_REPREPLACE);
}
*/

/*

  // Retrieving a SourceSafe Item History

  void v_DumpItemHistory(IVSSItemPtr vss_item)
  {
  int i_type = 0;
  IVSSVersionsPtr versions;
  
    vss_item->get_Type(&i_type);
    // Get the IVSSVersions object of the item
    if (vss_item->get_Versions((i_type == VSSITEM_PROJECT)? 
	VSSFLAG_HISTIGNOREFILES:0, &versions) == S_OK)
    {
	CComPtr<IENUMVARIANT> p_versionsEnum;
	CComPtr<IUNKNOWN> spunk;
	
	  versions->_NewEnum(&spunk);
	  spunk->QueryInterface(IID_IEnumVARIANT, (LPVOID*)&p_versionsEnum);
	  
        ULONG l_fetched;
        long l_value;
        CString str_display;
        CComBSTR bstr_text;
        DATE date;
		
		  // We use this object to point to each version
		  _variant_t object;
		  
			// Now iterate through all the versions
			while (p_versionsEnum->Next(1, &object, &l_fetched) == S_OK)
			{
            try
            {
			// Treat the object as IVSSVersion
			IVSSVersionPtr p_version(object);
			
			  // ...where we can get the version number
			  p_version->get_VersionNumber(&l_value);
			  // the user who did the changes
			  p_version->get_Username(&bstr_text);
			  ATLTRACE(_T("Version %d by %s"), l_value, bstr_text); 
			  // the date it was checked in
			  p_version->get_Date(&date);
			  // the action done
			  p_version->get_Action(&bstr_text);
			  ATLTRACE(_T(" On %s %s\n"), 
			  str_FormatDateTime(date), bstr_text);
			  }
			  catch (_com_error & e)
			  {
			  ATLTRACE(_T("%s\n"), e.ErrorMessage());
			  }
			  }
			  }
}

*/

/*

   // Traversing the Visual SourceSafe Database

  HTREEITEM CSSTreeCtrl::h_InsertPath(IVSSItemPtr vss_item, HTREEITEM h_parent, 
  CString & rstr_traverseToPath, HTREEITEM & rh_deepestNodeFound)
  {
  HTREEITEM h_item = NULL;
  try
  {
  CComBSTR str_name;
  v_TestHr(vss_item->get_Name(&str_name));
  CString str_Filename = static_cast<LPCTSTR>(str_name);
  if (h_parent == NULL)
  {
  str_Filename = gsz_root;
  }
  
	//Add the item into the tree node
	TV_INSERTSTRUCT tvis;
	ZeroMemory(&tvis, sizeof(TV_INSERTSTRUCT));
	tvis.hParent = h_parent;
	tvis.hInsertAfter = TVI_LAST;
	tvis.item.mask = TVIF_CHILDREN | TVIF_IMAGE | 
	TVIF_SELECTEDIMAGE | TVIF_TEXT | TVIF_PARAM;
	
	  tvis.item.lParam = NULL;
	  tvis.item.pszText = str_Filename.GetBuffer(str_Filename.GetLength());
	  
        IVSSItemsPtr vss_items;
        int i_type;
        long l_count, l_checkOut;
        vss_item->get_Type(&i_type);
        vss_item->get_IsCheckedOut(&l_checkOut);
        if (i_type == VSSITEM_FILE)
        {
		// Set image according to check out state
		if (l_checkOut == VSSFILE_NOTCHECKEDOUT)
		{
		tvis.item.iImage = ITEM_FILE_NORMAL_IMAGE;
		tvis.item.iSelectedImage = ITEM_FILE_NORMAL_IMAGE;
		}
		else
		{
		tvis.item.iImage = ITEM_FILE_CHECKOUT_IMAGE;
		tvis.item.iSelectedImage = ITEM_FILE_CHECKOUT_IMAGE;
		}
        }
        else if (i_type == VSSITEM_PROJECT)
        {
		vss_item->get_Items(_variant_t(false), &vss_items);
		tvis.item.iImage = ITEM_PROJECT_NORMAL_IMAGE;
		tvis.item.iSelectedImage = ITEM_PROJECT_SELECTED_IMAGE;
		vss_items->get_Count(&l_count);
		// Add (+) sign to indicate the node has child
		tvis.item.cChildren = (l_count > 0) ? 1:0;
        }
        h_item = InsertItem(&tvis);
		
		  // If this node is within the path, consider it as the deepest node
		  CString str_currentPath = str_ItemToPath(h_item);
		  ATLTRACE(_T("%s\n"),str_currentPath);
		  if (rstr_traverseToPath == str_currentPath)
		  {
		  rh_deepestNodeFound = h_item;
		  }
		  
			// If this node is not within the path, we're done
			if (h_parent && rstr_traverseToPath.Find(str_currentPath) != 0)
			{
            return h_item;
			}
			// Otherwise, recursively populate the node path
			if (i_type == VSSITEM_PROJECT)
			{
            for (long i = 0; i < l_count; i++)
            {
			IVSSItemPtr vss_ChildItem;
			vss_items->get_Item(_variant_t(i+1L), &vss_ChildItem);
			h_InsertPath(vss_ChildItem, h_item, 
			rstr_traverseToPath, rh_deepestNodeFound);
            }
			}
			}
			catch (_com_error &e)
			{
			ATLTRACE(_T("COM error: %s\n"), e.ErrorMessage());
			}
			
			  return h_item;
}
*/

//
#define CLSID_VSSItem		"{783CD4E3-9D54-11CF-B8EE-00608CC9A71F}"
#define IID_IVSSItem		"{2A0DE0E7-2E9F-11D0-9236-00AA00A1EB95}"
#define IID_IVSSItemOld		"{783CD4E1-9D54-11CF-B8EE-00608CC9A71F}"
//
#define CLSID_VSSVersion	"{783CD4EC-9D54-11CF-B8EE-00608CC9A71F}"
#define IID_IVSSVersion		"{2A0DE0E9-2E9F-11D0-9236-00AA00A1EB95}"
//
#define CLSID_VSSCheckOut	"{2A0DE0E0-2E9F-11D0-9236-00AA00A1EB95}"
#define IID_IVSSCheckOut	"{783CD4E6-9D54-11CF-B8EE-00608CC9A71F}"
//
#define CLSID_VSSDatabase	"{783CD4E4-9D54-11CF-B8EE-00608CC9A71F}"
#define IID_IVSSDatabase	"{2A0DE0E2-2E9F-11D0-9236-00AA00A1EB95}"
#define IID_IVSSDatabaseOld	"{783CD4E2-9D54-11CF-B8EE-00608CC9A71F}"
//
#define CLSID_VSSUser		"{2A0DE0E5-2E9F-11D0-9236-00AA00A1EB95}"
#define IID_IVSSUser		"{2A0DE0E3-2E9F-11D0-9236-00AA00A1EB95}"


CVSSMgr::CVSSMgr() : m_database(NULL) , m_b_opened(FALSE) , m_b_connected(FALSE)
{
}

CVSSMgr::~CVSSMgr()
{
	if(m_b_opened) Close();
}

BOOL CVSSMgr::IsVssInstalled()
{
	BOOL	bRet = FALSE;
	HKEY	hKey;
	DWORD	dwType;
	TCHAR	szServer[1024];
	DWORD   dwValue = 1024*sizeof(TCHAR);

	LONG hr = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
		_T("SOFTWARE\\Microsoft\\SourceSafe"),
		0,
		KEY_QUERY_VALUE,
		&hKey);
	if(SUCCEEDED(hr))
	{
		hr = RegQueryValueEx(hKey,
			_T("SCCServerPath"),
			0,
			&dwType,
			(LPBYTE)szServer,
			&dwValue);
		if(SUCCEEDED(hr))
		{
			bRet = TRUE;
		}
		RegCloseKey(hKey);
	}
	
	return bRet;
}

BOOL CVSSMgr::FileExits(LPWSTR fileName)
{
	BOOL	bRet = FALSE;
	DWORD	dwAttr;
	dwAttr = GetFileAttributesW(fileName);
	if( dwAttr != FILE_ATTRIBUTE_DIRECTORY &&
		!(dwAttr & INVALID_FILE_ATTRIBUTES)&&
		!(dwAttr & FILE_ATTRIBUTE_ARCHIVE) )
	{
		bRet = TRUE;
	}
	else
	{
		bRet = FALSE;
	}
	return bRet;
}

#if !defined(_UNICODE) && !defined(UNICODE)

BOOL CVSSMgr::FileExits(LPSTR fileName)
{
	BOOL	bRet = FALSE;
	DWORD	dwAttr;
	dwAttr = GetFileAttributes(fileName);
	if( dwAttr != FILE_ATTRIBUTE_DIRECTORY &&
		!(dwAttr & INVALID_FILE_ATTRIBUTES)&&
		!(dwAttr & FILE_ATTRIBUTE_ARCHIVE) )
	{
		bRet = TRUE;
	}
	else
	{
		bRet = FALSE;
	}
	return bRet;
}

#endif

VOID CVSSMgr::Close()
{
	_variant_t  result;
	HRESULT		hr;
	if(m_b_opened)
	{
		hr = m_database->CallInvoke(CComBSTR("Close"),result);	
	}
	if(m_database) delete m_database;
	m_database = NULL;
	m_b_opened = FALSE;
	m_b_connected = FALSE;
}

BOOL CVSSMgr::OpenDatabase(BSTR User,BSTR Password,BSTR srcIniFile)
{
	HRESULT hr;
	WCHAR  szDatabaseIni[MAX_PATH];
	DWORD  BufLen = MAX_PATH;
	LPWSTR pszIniFile = NULL;
	if(!srcIniFile)
	{
		if(GetDefaultDatabase(szDatabaseIni,&BufLen))
		{
			wcscat(szDatabaseIni,L"\\srcsafe.ini");
			pszIniFile = szDatabaseIni;
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		pszIniFile = srcIniFile;
	}

	if(!pszIniFile || FileExits(pszIniFile)) return FALSE;

	if(!m_database)	m_database = new CSRComHelper();

	if(!m_b_connected)
	{
		hr = m_database->Create(CComBSTR(CLSID_VSSDatabase));
		if(SUCCEEDED(hr)) m_b_connected = TRUE;
	}

	if(FAILED(hr))
	{
		delete m_database;
		m_database = NULL;
		return FALSE;
	}

	CComBSTR  database(pszIniFile);
	CComBSTR  user(User);
	CComBSTR  password(Password);
	_variant_t  result;

	m_database->CreateArray(3);
	m_database->SetParam(database);
	m_database->SetParam(user);
	m_database->SetParam(password);
	hr = m_database->CallInvoke(CComBSTR("Open"),result);
	if(SUCCEEDED(hr))
	{
		m_b_opened = TRUE;
	}
	m_database->Reset();

	return m_b_opened;
}

BOOL CVSSMgr::IsProjectExits(BSTR ProjectName)
{

	return FALSE;
}

HRESULT CVSSMgr::CheckIn(BSTR VSSPath,std::vector<BSTR*> &filesToCheckin)
{
	if(!m_database)
	{
		return E_FAIL;
	}



	return S_OK;
}

HRESULT CVSSMgr::Checkout(BSTR curDir,BSTR VSSPath)
{


	return S_OK;
}

BOOL CVSSMgr::GetDefaultDatabase(LPWSTR FilePathBuf,IN OUT PULONG BufLen)
{
	BOOL	bRet = FALSE;
	HKEY	hKey;
	DWORD	dwType;
	DWORD   dwValue = (*BufLen) * sizeof(WCHAR);

	LONG hr = RegOpenKeyExW(HKEY_LOCAL_MACHINE,
						L"SOFTWARE\\Microsoft\\SourceSafe",
						0,
						KEY_READ,
						&hKey);
	if(SUCCEEDED(hr))
	{
		hr = RegQueryValueExW(hKey,L"Current Database",0,&dwType,(LPBYTE)FilePathBuf,&dwValue);
		if(SUCCEEDED(hr))
		{
			*BufLen = dwValue/sizeof(WCHAR);
			bRet = TRUE;
		}
		RegCloseKey(hKey);
	}
	return bRet;
}