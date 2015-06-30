// ShellContextMenu.h: Definition of the CShellContextMenu class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHELLCONTEXTMENU_H__E42D6D95_FF1C_403D_9680_750E9B792CC5__INCLUDED_)
#define AFX_SHELLCONTEXTMENU_H__E42D6D95_FF1C_403D_9680_750E9B792CC5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols
#include <map>
#include <vector>
#include "PathUtils.h"
#include "ShellMgr.h"
/////////////////////////////////////////////////////////////////////////////
// CShellContextMenu

#define		COMMAND_INDEX_MAX	256

class CShellContextMenu : 
	public IDispatchImpl<IShellContextMenu, &IID_IShellContextMenu, &LIBID_SHELLOVERLAYLib>, 
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CShellContextMenu,&CLSID_ShellContextMenu>,
	public IContextMenu, 
    public IShellExtInit,
	public CShellMgr
{
public:
	CShellContextMenu() : m_pDataObj(NULL) , m_SelectItemCount(0)
	{
		m_szFileUserClickedOn[0] = _T('\0');
		m_WorkDir[0] = _T('\0');
		for(int i = 0 ; i < COMMAND_INDEX_MAX; i++)
		{
			m_idCmdMap[i] = 0;
		}
	}
	HRESULT FinalConstruct()
	{
		AtlTrace("FinalConstruct");
		return S_OK;
	}

	void FinalRelease()
	{
		AtlTrace("FinalRelease");
	}

BEGIN_COM_MAP(CShellContextMenu)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IShellContextMenu)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IShellExtInit)
	COM_INTERFACE_ENTRY(IContextMenu)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CShellContextMenu) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_ShellContextMenu)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IShellContextMenu
public:
	
	// IShellExtInit
public:
	STDMETHOD(Initialize)(LPCITEMIDLIST pIDFolder, 
		LPDATAOBJECT pDataObj, 
		HKEY hKeyID);
	
public:
	//IContextMenu methods
	STDMETHOD(QueryContextMenu)(HMENU hMenu,
		UINT indexMenu, 
		UINT idCmdFirst,
		UINT idCmdLast, 
		UINT uFlags);
	
	STDMETHOD(InvokeCommand)(LPCMINVOKECOMMANDINFO lpcmi);
	
	STDMETHOD(GetCommandString)(UINT idCmd, 
		UINT uFlags, 
		UINT FAR *reserved, 
		LPSTR pszName, 
		UINT cchMax);

protected:
	// Context Menu
	void InsertItem(HMENU hMenu,
		UINT MenuIndex,
		LPTSTR Text,
		UINT idCmd,
		HBITMAP hbmItem = NULL);
	void TweakMenu(HMENU hMenu);
	STDMETHODIMP DoMenu(HWND hParent, 
		UINT idCmd,
		LPCSTR pszWorkingDir,
		LPCSTR pszParam, 
        int iShowCmd);
	HBITMAP  CreateBitmapFromIcon(HINSTANCE hMod,UINT iconIndex);
	
protected:
	LPDATAOBJECT		m_pDataObj;
	UINT				m_SelectItemCount;
	TCHAR				m_WorkDir[4096];
	std::vector<LPTSTR> m_selected_items;
	TCHAR				m_szFileUserClickedOn[1024];
	UINT				m_idCmdMap[COMMAND_INDEX_MAX];
};

#endif // !defined(AFX_SHELLCONTEXTMENU_H__E42D6D95_FF1C_403D_9680_750E9B792CC5__INCLUDED_)
