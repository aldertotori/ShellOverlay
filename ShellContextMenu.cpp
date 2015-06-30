// ShellContextMenu.cpp : Implementation of CShellOverlayApp and DLL registration.

#include "stdafx.h"
#include "ShellOverlay.h"
#include "ShellContextMenu.h"
#include "VSSMgr.h"

/////////////////////////////////////////////////////////////////////////////
//
enum SourceSafe_Commands
{
	Source_Command_Null = 0,
	SourceSafe_Command_NewProject,
	SourceSafe_Command_CheckOut,
	SourceSafe_Command_CheckIn,
	SourceSafe_Command_Revert,
	SourceSafe_Command_Settings,
	SourceSafe_Command_About,
	SourceSafe_Command_MainMenu,
	SourceSafe_Command_Max
};

STDMETHODIMP CShellContextMenu::DoMenu(	HWND hParent,
									   UINT idCmd,
									   LPCSTR pszWorkingDir,
									   LPCSTR pszParam,
									   int iShowCmd)
{
	CString sccFile = pszWorkingDir;
	sccFile += _T("\\vssver2.scc");
	
	DWORD dwAttr = GetFileAttributes(sccFile);
	if( (dwAttr & FILE_ATTRIBUTE_DIRECTORY) ||
		(dwAttr & FILE_ATTRIBUTE_ARCHIVE)	)
	{
		return NOERROR;
	}
	
	switch(idCmd)
	{
	case SourceSafe_Command_NewProject:
		MessageBox(NULL,_T("New Project click"),NULL,MB_OK);
		break;
	case SourceSafe_Command_CheckOut:
		MessageBox(NULL,_T("CheckOut click"),NULL,MB_OK);
		break;
	case SourceSafe_Command_CheckIn:
		MessageBox(NULL,_T("CheckIn click"),NULL,MB_OK);
		break;
	case SourceSafe_Command_Revert:
		MessageBox(NULL,_T("Revert click"),NULL,MB_OK);
		break;
	case SourceSafe_Command_About:
		
		break;
	}
	
    return NOERROR;
}

STDMETHODIMP CShellContextMenu::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IShellContextMenu,
	};

	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (IsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CShellContextMenu::Initialize(	LPCITEMIDLIST pIDFolder,
										   LPDATAOBJECT pDataObj,
										   HKEY hRegKey)
{
	UINT Len = 4096;
	GetPathName(pIDFolder,m_WorkDir,&Len);
	
    if (m_pDataObj)
		m_pDataObj->Release();
	
    // duplicate the object pointer and registry handle
	
    if (pDataObj)
    {
		m_pDataObj = pDataObj;
		pDataObj->AddRef();
    }
	
    return S_OK;	
}

#define ResultFromShort(i)  ResultFromScode(MAKE_SCODE(SEVERITY_SUCCESS, 0, (USHORT)(i)))

STDMETHODIMP CShellContextMenu::QueryContextMenu(HMENU hMenu,
                                         UINT indexMenu,
                                         UINT idCmdFirst,
                                         UINT idCmdLast,
                                         UINT uFlags)
{



    UINT	idCmd = idCmdFirst;
    TCHAR	szMenuText[MAX_PATH];
    BOOL	bAppendItems=TRUE;

	HMENU	subMenu;
	TCHAR	szSubText[MAX_PATH];
	int		indexSubMenu = 0;

	MENUITEMINFO menuiteminfo = {0};

	// Vss check
	if(!CVSSMgr::IsVssInstalled()) return S_OK;

    if ((uFlags & 0x000F) == CMF_NORMAL)  //Check == here, since CMF_NORMAL=0
    {
        //lstrcpy(szMenuText, "&New .GAK menu 1, Normal File");
    }
    else if (uFlags & CMF_VERBSONLY)
	{
		//lstrcpy(szMenuText, "&New .GAK menu 1, Shortcut File");
	}
    else if (uFlags & CMF_EXPLORE)
	{
		//lstrcpy(szMenuText, "&New .GAK menu 1, Normal File right click in Explorer");
	}
    else if (uFlags & CMF_DEFAULTONLY)
	{
		bAppendItems = FALSE;
	}
    else
	{
		char szTemp[32];
		wsprintf(szTemp, "uFlags==>%d\r\n", uFlags);
		bAppendItems = FALSE;
	}

    if (bAppendItems)
    {
		subMenu = CreateMenu();
		
		if(subMenu)
		{
			// Add Project
			::LoadString(_Module.GetModuleInstance(),IDS_MENU_ADDPROJECT,szSubText,MAX_PATH);
			InsertItem( subMenu,
				indexSubMenu++,
				szSubText,
				idCmd++,
				(HBITMAP)CreateBitmapFromIcon((HINSTANCE)_Module.GetModuleInstance(), 
				IDI_MENU_NEWPROJECT)
				);
			
			m_idCmdMap[idCmd-idCmdFirst] = SourceSafe_Command_NewProject;
			
			// Checkout
			::LoadString(_Module.GetModuleInstance(),IDS_MENU_CHECKOUT,szSubText,MAX_PATH);
			InsertItem( subMenu,
				indexSubMenu++,
				szSubText,
				idCmd++,
				(HBITMAP)CreateBitmapFromIcon((HINSTANCE)_Module.GetModuleInstance(), IDI_MENU_CHECKOUT)
				);
			
			m_idCmdMap[idCmd-idCmdFirst] = SourceSafe_Command_CheckOut;
			
			// SourceSafe_Command_Checkin
			::LoadString(_Module.GetModuleInstance(),IDS_MENU_CHECKIN,szSubText,MAX_PATH);
			InsertItem( subMenu,
				indexSubMenu++,
				szSubText,
				idCmd++,
				(HBITMAP)CreateBitmapFromIcon((HINSTANCE)_Module.GetModuleInstance(), IDI_MENU_CHECKIN)
				);
			
			m_idCmdMap[idCmd-idCmdFirst] = SourceSafe_Command_CheckIn;
			
			// SourceSafe_Command_Revert
			::LoadString(_Module.GetModuleInstance(),IDS_MENU_REVERT,szSubText,MAX_PATH);
			InsertItem( subMenu,
				indexSubMenu++,
				szSubText,
				idCmd++,
				(HBITMAP)CreateBitmapFromIcon((HINSTANCE)_Module.GetModuleInstance(), IDI_MENU_REVERT)
				);
			m_idCmdMap[idCmd-idCmdFirst] = SourceSafe_Command_Revert;
			
			//
			InsertMenu(subMenu, indexSubMenu++, MF_SEPARATOR|MF_BYPOSITION, 0, NULL);
			
			// Source_Command_About
			::LoadString(_Module.GetModuleInstance(),IDS_MENU_ABOUT,szSubText,MAX_PATH);
			InsertItem( subMenu,
				indexSubMenu++,
				szSubText,
				idCmd++,
				NULL);
			m_idCmdMap[idCmd-idCmdFirst] = SourceSafe_Command_About;

			TweakMenu(subMenu);
		
		}
		
		// main menu
		InsertMenu(hMenu, indexMenu++, MF_SEPARATOR|MF_BYPOSITION, 0, NULL);

		::LoadString(_Module.GetModuleInstance(),IDS_MENU_SOURCESAFE,szMenuText,MAX_PATH);
		menuiteminfo.cbSize = sizeof(MENUITEMINFO);
		menuiteminfo.fMask = MIIM_FTYPE | MIIM_ID | MIIM_SUBMENU | MIIM_CHECKMARKS | MIIM_STRING; // | MIIM_DATA | MIIM_BITMAP
		menuiteminfo.fType = MFT_STRING ;
		menuiteminfo.dwTypeData = szMenuText;
		menuiteminfo.hSubMenu = subMenu;
		menuiteminfo.wID = (UINT)idCmd++;
		HBITMAP hBm = (HBITMAP)CreateBitmapFromIcon((HINSTANCE)_Module.GetModuleInstance(), IDI_MENU_MAIN);
		//menuiteminfo.hbmpItem = hBm;
		menuiteminfo.hbmpChecked = hBm;
		menuiteminfo.hbmpUnchecked = hBm;
		InsertMenuItem(hMenu, indexMenu++, TRUE, &menuiteminfo);
		
        return ResultFromShort(idCmd-idCmdFirst); //Must return number of menu
	}

	return NOERROR;

}

void CShellContextMenu::InsertItem(HMENU hMenu,UINT MenuIndex,LPTSTR Text,UINT idCmd,HBITMAP hbmItem)
{
	MENUITEMINFO	iteminfo;
	iteminfo.cbSize = sizeof(MENUITEMINFO);
	iteminfo.fMask = MIIM_FTYPE | MIIM_ID | MIIM_STRING;
	iteminfo.fType = MFT_STRING;
	iteminfo.dwTypeData = Text;
	if(hbmItem)
	{
		iteminfo.fMask |= MIIM_BITMAP;
		iteminfo.hbmpItem = hbmItem;
	}
	iteminfo.wID = (UINT)idCmd;
	InsertMenuItem(hMenu, MenuIndex, TRUE, &iteminfo);
}

STDMETHODIMP CShellContextMenu::InvokeCommand(LPCMINVOKECOMMANDINFO lpcmi)
{
	HRESULT hr = E_INVALIDARG;
	
    //If HIWORD(lpcmi->lpVerb) then we have been called programmatically
    //and lpVerb is a command that should be invoked.  Otherwise, the shell
    //has called us, and LOWORD(lpcmi->lpVerb) is the menu ID the user has
    //selected.  Actually, it's (menu ID - idCmdFirst) from QueryContextMenu().
	if (!HIWORD(lpcmi->lpVerb))
    {
        UINT idIndex = LOWORD(lpcmi->lpVerb);
		if(idIndex < SourceSafe_Command_Max)
		{
			hr = DoMenu(lpcmi->hwnd,
				m_idCmdMap[idIndex],
				lpcmi->lpDirectory,
				lpcmi->lpParameters,
				lpcmi->nShow);
		}
    }
    return hr;
}

STDMETHODIMP CShellContextMenu::GetCommandString(UINT idCmd,
                                         UINT uFlags,
                                         UINT FAR *reserved,
                                         LPSTR pszName,
                                         UINT cchMax)
{
	char		szHelp[MAX_PATH];
	WCHAR		wzHelp[MAX_PATH];
	switch(uFlags)
	{
	case GCS_HELPTEXTA:
		switch (idCmd)
		{
        case SourceSafe_Command_MainMenu:
            lstrcpyA(pszName, "&SourceSafe");
            break;
			
        case SourceSafe_Command_CheckOut:
            lstrcpyA(pszName, "Check &out");
            break;
			
        case SourceSafe_Command_CheckIn:
            lstrcpyA(pszName, "Check &in");
            break;
			
        case SourceSafe_Command_NewProject:
            lstrcpyA(pszName, "&Add project");
            break;
		case SourceSafe_Command_Revert:
			lstrcpyA(pszName, "Re&vert");
			break;
		case SourceSafe_Command_About:
			lstrcpyA((LPSTR)pszName, "About Sourcesafe shell");
			break;
		}
		break;
	case GCS_HELPTEXTW:
		switch (idCmd)
		{
        case SourceSafe_Command_MainMenu:
            lstrcpyW((LPWSTR)pszName, L"&SourceSafe");
            break;
			
        case SourceSafe_Command_CheckOut:
            lstrcpyW((LPWSTR)pszName, L"Check &out");
            break;
			
        case SourceSafe_Command_CheckIn:
            lstrcpyW((LPWSTR)pszName, L"Check &in");
            break;
			
        case SourceSafe_Command_NewProject:
            lstrcpyW((LPWSTR)pszName, L"&Add project");
            break;
		case SourceSafe_Command_Revert:
			lstrcpyW((LPWSTR)pszName, L"Re&vert");
			break;
		case SourceSafe_Command_About:
			lstrcpyW((LPWSTR)pszName, L"About Sourcesafe shell");
			break;
		}
		break;
	case GCS_VERBA:
		switch (idCmd)
		{
        case SourceSafe_Command_MainMenu:
            lstrcpyA((LPSTR)pszName, "SourceSafe version control");
            break;
			
        case SourceSafe_Command_CheckOut:
            lstrcpyA((LPSTR)pszName, "Check out code from SourceSafe");
            break;
			
        case SourceSafe_Command_CheckIn:
            lstrcpyA((LPSTR)pszName, "Check code to SourceSafe");
            break;
			
        case SourceSafe_Command_NewProject:
            lstrcpyA((LPSTR)pszName, "Add SourceSafe project");
            break;
		case SourceSafe_Command_Revert:
			lstrcpyA((LPSTR)pszName, "Revert code to old version");
			break;
		case SourceSafe_Command_About:
			lstrcpyA((LPSTR)pszName, "About Sourcesafe shell");
			break;
		}
		break;
	case GCS_VERBW:
		switch (idCmd)
		{
        case SourceSafe_Command_MainMenu:
            lstrcpyW((LPWSTR)pszName, L"SourceSafe version control");
            break;
			
        case SourceSafe_Command_CheckOut:
            lstrcpyW((LPWSTR)pszName, L"Check out code from SourceSafe");
            break;
			
        case SourceSafe_Command_CheckIn:
            lstrcpyW((LPWSTR)pszName, L"Check code to SourceSafe");
            break;
			
        case SourceSafe_Command_NewProject:
            lstrcpyW((LPWSTR)pszName, L"Add SourceSafe project");
            break;
		case SourceSafe_Command_Revert:
			lstrcpyW((LPWSTR)pszName, L"Revert code to old version");
			break;
		case SourceSafe_Command_About:
			lstrcpyW((LPWSTR)pszName, L"About Sourcesafe shell");
			break;
		}
		break;
	}
    return S_OK;
}

void CShellContextMenu::TweakMenu(HMENU hMenu)
{
    MENUINFO MenuInfo = { 0 };
    MenuInfo.cbSize  = sizeof(MenuInfo);
    MenuInfo.fMask   = MIM_STYLE;
	GetMenuInfo(hMenu,&MenuInfo);
    MenuInfo.dwStyle |= MNS_CHECKORBMP;
    SetMenuInfo(hMenu, &MenuInfo);
}


HBITMAP ConvertIconToBitmap(HICON hIcon)
{
	//LONG Dim = GetMenuCheckMarkDimensions();
	int cx = GetSystemMetrics(SM_CXSMICON);
	int cy = GetSystemMetrics(SM_CYSMICON);
	ICONINFO	iconInfo;
	BITMAP		bitmap = {0};
	
	GetIconInfo(hIcon,&iconInfo);
	GetObject(iconInfo.hbmColor, sizeof(bitmap), &bitmap);
	DeleteObject(iconInfo.hbmColor);
	DeleteObject(iconInfo.hbmMask);
	
	HBITMAP bmp;
	HDC bmpDC = GetDC(NULL);
	HDC dcMem = ::CreateCompatibleDC(bmpDC);
	
	bmp = ::CreateCompatibleBitmap(bmpDC, cx, cy);
	HBITMAP pOldBmp = (HBITMAP)SelectObject(dcMem,bmp);
	if( bitmap.bmWidth < cx &&
		bitmap.bmHeight < cy)
	{
		::DrawIconEx(dcMem, 
			(cx-bitmap.bmWidth)/2, 
			(cy - bitmap.bmHeight)/2,
			hIcon, bitmap.bmWidth, 
			bitmap.bmHeight, 
			0, 
			(HBRUSH)GetSysColorBrush(COLOR_MENU), 
			DI_NORMAL);
	}
	else
	{
		::DrawIconEx(dcMem, 0, 0, hIcon, cx, cy, 0, (HBRUSH)GetSysColorBrush(COLOR_MENU), DI_NORMAL);
	}
	SelectObject(dcMem,pOldBmp);
	DeleteObject(dcMem);
	ReleaseDC(NULL, bmpDC);
	HBITMAP hBitmap = (HBITMAP)::CopyImage((HANDLE)((HBITMAP)bmp), IMAGE_BITMAP, 0, 0, LR_DEFAULTSIZE);
	DeleteObject(bmp);
	return hBitmap;
}

HBITMAP  CShellContextMenu::CreateBitmapFromIcon(HINSTANCE hMod,UINT iconIndex)
{
	HBITMAP		hBitmap = NULL;
	HICON  hIcon = (HICON)LoadImage(hMod,MAKEINTRESOURCE(iconIndex),IMAGE_ICON,GetSystemMetrics(SM_CXSMICON),GetSystemMetrics(SM_CYSMICON),LR_DEFAULTCOLOR); //
	if(hIcon)
	{
		hBitmap = ConvertIconToBitmap(hIcon);
		DestroyIcon(hIcon);
	}
	return hBitmap;
}
