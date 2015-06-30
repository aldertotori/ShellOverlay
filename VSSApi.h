
#pragma once
#pragma pack(push, 8)

#include <comdef.h>

//
// Type library items
//

enum SourceSafeTypeLibVersion
{
    SOURCESAFE_TYPELIB_VERSION_MAJOR = 5,
	SOURCESAFE_TYPELIB_VERSION_MINOR = 2
};

enum VSSFlags
{
    VSSFLAG_USERRONO = 1,
	VSSFLAG_USERROYES = 2,
	VSSFLAG_TIMENOW = 4,
	VSSFLAG_TIMEMOD = 8,
	VSSFLAG_TIMEUPD = 12,
	VSSFLAG_EOLCR = 16,
	VSSFLAG_EOLLF = 32,
	VSSFLAG_EOLCRLF = 48,
	VSSFLAG_REPASK = 64,
	VSSFLAG_REPREPLACE = 128,
	VSSFLAG_REPSKIP = 192,
	VSSFLAG_REPMERGE = 256,
	VSSFLAG_CMPFULL = 512,
	VSSFLAG_CMPTIME = 1024,
	VSSFLAG_CMPCHKSUM = 1536,
	VSSFLAG_CMPFAIL = 2048,
	VSSFLAG_RECURSNO = 4096,
	VSSFLAG_RECURSYES = 8192,
	VSSFLAG_FORCEDIRNO = 16384,
	VSSFLAG_FORCEDIRYES = 32768,
	VSSFLAG_KEEPNO = 0x10000,
	VSSFLAG_KEEPYES = 0x20000,
	VSSFLAG_DELNO = 0x40000,
	VSSFLAG_DELYES = 0x80000,
	VSSFLAG_DELNOREPLACE = 0xC0000,
	VSSFLAG_BINTEST = 0x100000,
	VSSFLAG_BINBINARY = 0x200000,
	VSSFLAG_BINTEXT = 0x300000,
	VSSFLAG_DELTAYES = 0x400000,
	VSSFLAG_DELTANO = 0x800000,
	VSSFLAG_UPDASK = 0x1000000,
	VSSFLAG_UPDUPDATE = 0x2000000,
	VSSFLAG_UPDUNCH = 0x3000000,
	VSSFLAG_GETYES = 0x4000000,
	VSSFLAG_GETNO = 0x8000000,
	VSSFLAG_CHKEXCLUSIVEYES = 0x10000000,
	VSSFLAG_CHKEXCLUSIVENO = 0x20000000,
	VSSFLAG_HISTIGNOREFILES = 0x40000000,
	VSSFLAG_CKOUTLOCALVER = 0x80000000
};

enum VSSFileStatus
{
    VSSFILE_NOTCHECKEDOUT = 0,
	VSSFILE_CHECKEDOUT = 1,
	VSSFILE_CHECKEDOUT_ME = 2
};

enum VSSItemType
{
    VSSITEM_PROJECT = 0,
	VSSITEM_FILE = 1
};

enum VSSRights
{
    VSSRIGHTS_READ = 1,
	VSSRIGHTS_CHKUPD = 2,
	VSSRIGHTS_ADDRENREM = 4,
	VSSRIGHTS_DESTROY = 8,
	VSSRIGHTS_ALL = 15,
	VSSRIGHTS_INHERITED = 16
};

enum VSSItemEncoding
{
    VSSENCODING_ANSI = 0,
	VSSENCODING_BINARY = 1,
	VSSENCODING_UNICODE = 2,
	VSSENCODING_UNICODE_UTF8 = 3,
	VSSENCODING_UNICODE_BIG_ENDIAN = 4
};

enum VSSCheckoutType
{
    VSSCHECKOUT_SHARED = 0,
	VSSCHECKOUT_EXCLUSIVE = 1
};


//EXTERN_C const IID IID_IVSSEventHandler;

#if defined(__cplusplus) && !defined(CINTERFACE)

MIDL_INTERFACE("783CD4EA-9D54-11CF-B8EE-00608CC9A71F")
IVSSEventHandler : public IUnknown
{
    public:
		HRESULT STDMETHODCALLTYPE Init(IUnknown* pIVSS);
};

#else 	/* C style interface */

typedef struct IVSSEventHandlerVtbl
{
	BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
		IVSSEventHandler * This,
		/* [in] */ REFIID riid,
		/* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
		IVSSEventHandler * This);
	
	ULONG ( STDMETHODCALLTYPE *Release )( 
		IVSSEventHandler * This);

	HRESULT (STDMETHODCALLTYPE *Init)(
		IVSSEventHandler* This,
		IUnknown* pIVSS);

        END_INTERFACE
} IBidiSplVtbl;

interface IBidiSpl
{
	CONST_VTBL struct IVSSEventHandlerVtbl *lpVtbl;
};

#ifdef COBJMACROS

#define IVSSEventHandler_QueryInterface(This,riid,ppvObject)	\
(This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVSSEventHandler_AddRef(This)	\
(This)->lpVtbl -> AddRef(This)

#define IVSSEventHandler_Release(This)	\
(This)->lpVtbl -> Release(This)

#define IVSSEventHandler_Init(This,pIVSS)	\
(This)->lpVtbl ->Init(This,pIVSS)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#pragma pack(pop)

/*
[
  uuid(783CD4E0-9D54-11CF-B8EE-00608CC9A71F),
  version(5.2),
  helpstring("Microsoft SourceSafe 8.0 Type Library")
]
library SourceSafeTypeLib
{
    // TLib :     // TLib : OLE Automation : {00020430-0000-0000-C000-000000000046}
    importlib("STDOLE2.TLB");

    // Forward declare all types defined in this typelib
    interface IVSSItemOld;
    interface IVSSItemOld1;
    interface IVSSItem;
    interface IVSSVersionsOld;
    interface IVSSVersions;
    interface IVSSVersionOld;
    interface IVSSVersion;
    interface IVSSItems;
    interface IVSSCheckouts;
    interface IVSSCheckoutOld;
    interface IVSSCheckout;
    interface IVSSCheckoutModifiable;
    interface IVSSDatabaseOld;
    interface IVSSDatabaseOld1;
    interface IVSSDatabase;
    interface IVSSUser;
    interface IVSSUsers;
    interface IVSSEventsOld;
    interface IVSSEvents;
    interface IVSS;
    interface IVSSEventHandler;

    typedef [uuid(2A0DE0F1-2E9F-11D0-9236-00AA00A1EB95), helpstring("SourceSafe operation flags")]
    enum {
        SOURCESAFE_TYPELIB_VERSION_MAJOR = 5,
        SOURCESAFE_TYPELIB_VERSION_MINOR = 2
    } SourceSafeTypeLibVersion;

    typedef [uuid(783CD4EF-9D54-11CF-B8EE-00608CC9A71F), helpstring("SourceSafe operation flags")]
    enum {
        VSSFLAG_USERRONO = 1,
        VSSFLAG_USERROYES = 2,
        VSSFLAG_TIMENOW = 4,
        VSSFLAG_TIMEMOD = 8,
        VSSFLAG_TIMEUPD = 12,
        VSSFLAG_EOLCR = 16,
        VSSFLAG_EOLLF = 32,
        VSSFLAG_EOLCRLF = 48,
        VSSFLAG_REPASK = 64,
        VSSFLAG_REPREPLACE = 128,
        VSSFLAG_REPSKIP = 192,
        VSSFLAG_REPMERGE = 256,
        VSSFLAG_CMPFULL = 512,
        VSSFLAG_CMPTIME = 1024,
        VSSFLAG_CMPCHKSUM = 1536,
        VSSFLAG_CMPFAIL = 2048,
        VSSFLAG_RECURSNO = 4096,
        VSSFLAG_RECURSYES = 8192,
        VSSFLAG_FORCEDIRNO = 16384,
        VSSFLAG_FORCEDIRYES = 32768,
        VSSFLAG_KEEPNO = 0x00010000,
        VSSFLAG_KEEPYES = 0x00020000,
        VSSFLAG_DELNO = 0x00040000,
        VSSFLAG_DELYES = 0x00080000,
        VSSFLAG_DELNOREPLACE = 0x000c0000,
        VSSFLAG_BINTEST = 0x00100000,
        VSSFLAG_BINBINARY = 0x00200000,
        VSSFLAG_BINTEXT = 0x00300000,
        VSSFLAG_DELTAYES = 0x00400000,
        VSSFLAG_DELTANO = 0x00800000,
        VSSFLAG_UPDASK = 0x01000000,
        VSSFLAG_UPDUPDATE = 0x02000000,
        VSSFLAG_UPDUNCH = 0x03000000,
        VSSFLAG_GETYES = 0x04000000,
        VSSFLAG_GETNO = 0x08000000,
        VSSFLAG_CHKEXCLUSIVEYES = 0x10000000,
        VSSFLAG_CHKEXCLUSIVENO = 0x20000000,
        VSSFLAG_HISTIGNOREFILES = 0x40000000,
        VSSFLAG_CKOUTLOCALVER = 0x80000000
    } VSSFlags;

    typedef [uuid(783CD4ED-9D54-11CF-B8EE-00608CC9A71F), helpstring("SourceSafe file checkout status")]
    enum {
        VSSFILE_NOTCHECKEDOUT = 0,
        VSSFILE_CHECKEDOUT = 1,
        VSSFILE_CHECKEDOUT_ME = 2
    } VSSFileStatus;

    typedef [uuid(783CD4EE-9D54-11CF-B8EE-00608CC9A71F), helpstring("SourceSafe item type")]
    enum {
        VSSITEM_PROJECT = 0,
        VSSITEM_FILE = 1
    } VSSItemType;

    typedef [uuid(2A0DE0E6-2E9F-11D0-9236-00AA00A1EB95), helpstring("SourceSafe rights values")]
    enum {
        VSSRIGHTS_READ = 1,
        VSSRIGHTS_CHKUPD = 2,
        VSSRIGHTS_ADDRENREM = 4,
        VSSRIGHTS_DESTROY = 8,
        VSSRIGHTS_ALL = 15,
        VSSRIGHTS_INHERITED = 16
    } VSSRights;

    typedef [uuid(2A0DE0EC-2E9F-11D0-9236-00AA00A1EB95), helpstring("SourceSafe item encoding")]
    enum {
        VSSENCODING_ANSI = 0,
        VSSENCODING_BINARY = 1,
        VSSENCODING_UNICODE = 2,
        VSSENCODING_UNICODE_UTF8 = 3,
        VSSENCODING_UNICODE_BIG_ENDIAN = 4
    } VSSItemEncoding;

    typedef [uuid(2A0DE0EF-2E9F-11D0-9236-00AA00A1EB95), helpstring("SourceSafe checkout type")]
    enum {
        VSSCHECKOUT_SHARED = 0,
        VSSCHECKOUT_EXCLUSIVE = 1
    } VSSCheckoutType;

    [
      odl,
      uuid(783CD4E1-9D54-11CF-B8EE-00608CC9A71F),
      helpstring("SourceSafe item interface"),
      dual,
      oleautomation
    ]
    interface IVSSItemOld : IDispatch {
        [id(0x00000001), propget]
        HRESULT Spec([out, retval] BSTR* pSpec);
        [id(0x00000002), propget]
        HRESULT Binary([out, retval] VARIANT_BOOL* pbBinary);
        [id(0x00000002), propput]
        HRESULT Binary([in] VARIANT_BOOL pbBinary);
        [id(0x00000003), propget]
        HRESULT Deleted([out, retval] VARIANT_BOOL* pbDeleted);
        [id(0x00000003), propput]
        HRESULT Deleted([in] VARIANT_BOOL pbDeleted);
        [id(0x00000004), propget]
        HRESULT Type([out, retval] int* piType);
        [id(0x00000005), propget]
        HRESULT LocalSpec([out, retval] BSTR* pLocal);
        [id(0x00000005), propput]
        HRESULT LocalSpec([in] BSTR pLocal);
        [id(0x00000006), propget]
        HRESULT Name([out, retval] BSTR* pName);
        [id(0x00000006), propput]
        HRESULT Name([in] BSTR pName);
        [id(0x00000007), propget]
        HRESULT Parent([out, retval] IVSSItem** ppIParent);
        [id(0x00000008), propget]
        HRESULT VersionNumber([out, retval] long* piVersion);
        [id(0x00000009), propget]
        HRESULT Items(
                        [in, optional, defaultvalue(0)] VARIANT_BOOL IncludeDeleted, 
                        [out, retval] IVSSItems** ppIItems);
        [id(0x0000000a)]
        HRESULT Get(
                        [in, out, optional, defaultvalue("")] BSTR* Local, 
                        [in, optional, defaultvalue(0)] long iFlags);
        [id(0x0000000b)]
        HRESULT Checkout(
                        [in, optional, defaultvalue("")] BSTR Comment, 
                        [in, optional, defaultvalue("")] BSTR Local, 
                        [in, optional, defaultvalue(0)] long iFlags);
        [id(0x0000000c)]
        HRESULT Checkin(
                        [in, optional, defaultvalue("")] BSTR Comment, 
                        [in, optional, defaultvalue("")] BSTR Local, 
                        [in, optional, defaultvalue(0)] long iFlags);
        [id(0x0000000d)]
        HRESULT UndoCheckout(
                        [in, optional, defaultvalue("")] BSTR Local, 
                        [in, optional, defaultvalue(0)] long iFlags);
        [id(0x0000000e), propget]
        HRESULT IsCheckedOut([out, retval] long* piStatus);
        [id(0x0000000f), propget]
        HRESULT Checkouts([out, retval] IVSSCheckouts** ppICheckouts);
        [id(0x00000010), propget]
        HRESULT IsDifferent(
                        [in, optional, defaultvalue("")] BSTR Local, 
                        [out, retval] VARIANT_BOOL* pbDifferent);
        [id(0x00000011)]
        HRESULT Add(
                        [in] BSTR Local, 
                        [in, optional, defaultvalue("")] BSTR Comment, 
                        [in, optional, defaultvalue(0)] long iFlags, 
                        [out, retval] IVSSItem** ppIItem);
        [id(0x00000012)]
        HRESULT NewSubproject(
                        [in] BSTR Name, 
                        [in, optional, defaultvalue("")] BSTR Comment, 
                        [out, retval] IVSSItem** ppIItem);
        [id(0x00000013)]
        HRESULT Share(
                        [in] IVSSItem* pIItem, 
                        [in, optional, defaultvalue("")] BSTR Comment, 
                        [in, optional, defaultvalue(0)] long iFlags);
        [id(0x00000014)]
        HRESULT Destroy();
        [id(0x00000015)]
        HRESULT Move([in] IVSSItem* pINewParent);
        [id(0x00000016)]
        HRESULT Label(
                        [in] BSTR Label, 
                        [in, optional, defaultvalue("")] BSTR Comment);
        [id(0x00000017), propget]
        HRESULT Versions(
                        [in, optional, defaultvalue(0)] long iFlags, 
                        [out, retval] IVSSVersions** pIVersions);
        [id(0x00000018), propget]
        HRESULT Version(
                        [in, optional] VARIANT Version, 
                        [out, retval] IVSSItem** ppIItem);
    };

    [
      odl,
      uuid(2A0DE0E7-2E9F-11D0-9236-00AA00A1EB95),
      helpstring("SourceSafe item interface"),
      dual,
      oleautomation
    ]
    interface IVSSItemOld1 : IVSSItemOld {
        [id(0x00000019), propget]
        HRESULT Links([out, retval] IVSSItems** ppIItems);
        [id(0x0000001a)]
        HRESULT Branch(
                        [in, optional, defaultvalue("")] BSTR Comment, 
                        [in, optional, defaultvalue(0)] long iFlags, 
                        [out, retval] IVSSItem** ppIItem);
    };

    [
      odl,
      uuid(2A0DE0EA-2E9F-11D0-9236-00AA00A1EB95),
      helpstring("SourceSafe item interface"),
      dual,
      oleautomation
    ]
    interface IVSSItem : IVSSItemOld1 {
        [id(0x0000001b), propget]
        HRESULT Child(
                        [in] BSTR Spec, 
                        [in, optional, defaultvalue(0)] VARIANT_BOOL Deleted, 
                        [out, retval] IVSSItem** ppIVSSItem);
        [id(0x0000001c), propget]
        HRESULT VSSVersion([out, retval] IVSSVersion** ppIVersion);
        [id(0x0000001d), propget]
        HRESULT Encoding([out, retval] VSSItemEncoding* pItemEncoding);
        [id(0x0000001d), propput]
        HRESULT Encoding([in] VSSItemEncoding pItemEncoding);
        [id(0x0000001e), propget]
        HRESULT AutoDetectEncoding([out, retval] VARIANT_BOOL* pbAutoDetectEncoding);
        [id(0x0000001e), propput]
        HRESULT AutoDetectEncoding([in] VARIANT_BOOL pbAutoDetectEncoding);
        [id(0x0000001f)]
        HRESULT AddWithEncoding(
                        [in] BSTR Local, 
                        [in] VSSItemEncoding ItemEncoding, 
                        [in, optional, defaultvalue("")] BSTR Comment, 
                        [in, optional, defaultvalue(0)] long iFlags, 
                        [out, retval] IVSSItem** ppIItem);
        [id(0x00000020), propget]
        HRESULT Physical([out, retval] BSTR* pPhysical);
        [id(0x00000021), propget]
        HRESULT CRC([out, retval] long* pCRC);
        [id(0x00000022), propget]
        HRESULT IsPinned([out, retval] VARIANT_BOOL* pbBinary);
        [id(0x00000023), propget]
        HRESULT Size([out, retval] long* piSize);
    };

    [
      odl,
      uuid(783CD4E7-9D54-11CF-B8EE-00608CC9A71F),
      helpstring("SourceSafe versions collection"),
      dual,
      oleautomation
    ]
    interface IVSSVersionsOld : IDispatch {
        [id(0xfffffffc), restricted, hidden]
        HRESULT _NewEnum([out, retval] IUnknown** ppIEnum);
    };

    [
      odl,
      uuid(2A0DE0EB-2E9F-11D0-9236-00AA00A1EB95),
      helpstring("SourceSafe items collection interface"),
      dual,
      oleautomation
    ]
    interface IVSSVersions : IVSSVersionsOld {
        [id(0x00000001), propget]
        HRESULT Count([out, retval] long* piCount);
        [id(00000000), propget]
        HRESULT Item(
                        [in] VARIANT sItem, 
                        [out, retval] IVSSVersion** ppIVersion);
    };

    [
      odl,
      uuid(783CD4E8-9D54-11CF-B8EE-00608CC9A71F),
      helpstring("SourceSafe version information"),
      dual,
      oleautomation
    ]
    interface IVSSVersionOld : IDispatch {
        [id(0x00000001), propget]
        HRESULT Username([out, retval] BSTR* pUsername);
        [id(0x00000002), propget]
        HRESULT VersionNumber([out, retval] long* piVersion);
        [id(0x00000003), propget]
        HRESULT Action([out, retval] BSTR* pAction);
        [id(0x00000004), propget]
        HRESULT Date([out, retval] DATE* pDate);
        [id(0x00000005), propget]
        HRESULT Comment([out, retval] BSTR* pComment);
        [id(0x00000006), propget]
        HRESULT Label([out, retval] BSTR* pLabel);
        [id(0x00000007), propget]
        HRESULT VSSItem([out, retval] IVSSItem** ppIItem);
    };

    [
      odl,
      uuid(2A0DE0E9-2E9F-11D0-9236-00AA00A1EB95),
      helpstring("SourceSafe version information"),
      dual,
      oleautomation
    ]
    interface IVSSVersion : IVSSVersionOld {
        [id(0x00000008), propget]
        HRESULT LabelComment([out, retval] BSTR* pComment);
    };

    [
      odl,
      uuid(783CD4E5-9D54-11CF-B8EE-00608CC9A71F),
      helpstring("SourceSafe items collection interface"),
      dual,
      oleautomation
    ]
    interface IVSSItems : IDispatch {
        [id(0x00000001), propget]
        HRESULT Count([out, retval] long* piCount);
        [id(00000000), propget]
        HRESULT Item(
                        [in] VARIANT sItem, 
                        [out, retval] IVSSItem** ppIItem);
        [id(0xfffffffc), restricted, hidden]
        HRESULT _NewEnum([out, retval] IUnknown** ppIEnum);
    };

    [
      odl,
      uuid(8903A770-F55F-11CF-9227-00AA00A1EB95),
      helpstring("SourceSafe checkouts collection interface"),
      dual,
      oleautomation
    ]
    interface IVSSCheckouts : IDispatch {
        [id(0x00000001), propget]
        HRESULT Count([out, retval] long* piCount);
        [id(00000000), propget]
        HRESULT Item(
                        [in] VARIANT sItem, 
                        [out, retval] IVSSCheckout** ppICheckout);
        [id(0xfffffffc), restricted, hidden]
        HRESULT _NewEnum([out, retval] IUnknown** ppIEnum);
    };

    [
      odl,
      uuid(783CD4E6-9D54-11CF-B8EE-00608CC9A71F),
      helpstring("SourceSafe checkouts interface"),
      dual,
      oleautomation
    ]
    interface IVSSCheckoutOld : IDispatch {
        [id(0x00000001), propget]
        HRESULT Username([out, retval] BSTR* pUsername);
        [id(0x00000002), propget]
        HRESULT Date([out, retval] DATE* pDate);
        [id(0x00000003), propget]
        HRESULT LocalSpec([out, retval] BSTR* pLocal);
        [id(0x00000004), propget]
        HRESULT Machine([out, retval] BSTR* pMachine);
        [id(0x00000005), propget]
        HRESULT Project([out, retval] BSTR* pProject);
        [id(0x00000006), propget]
        HRESULT Comment([out, retval] BSTR* pComment);
        [id(0x00000007), propget]
        HRESULT VersionNumber([out, retval] long* piVersion);
    };

    [
      odl,
      uuid(2A0DE0F0-2E9F-11D0-9236-00AA00A1EB95),
      helpstring("SourceSafe checkout properties"),
      dual,
      oleautomation
    ]
    interface IVSSCheckout : IVSSCheckoutOld {
        [id(0x00000008), propget]
        HRESULT CheckoutType([out, retval] VSSCheckoutType* pType);
    };

    [
      odl,
      uuid(2A0DE0ED-2E9F-11D0-9236-00AA00A1EB95),
      helpstring("SourceSafe checkout modifiable properties"),
      dual,
      oleautomation
    ]
    interface IVSSCheckoutModifiable : IVSSCheckout {
        [id(0x00000009), propput]
        HRESULT NewLocalSpec([in] BSTR rhs);
        [id(0x0000000a), propput]
        HRESULT NewMachine([in] BSTR rhs);
        [id(0x0000000b), propput]
        HRESULT NewVersionNumber([in] long rhs);
        [id(0x0000000c), propput]
        HRESULT NewLastMerge([in] long rhs);
    };

    [
      odl,
      uuid(783CD4E2-9D54-11CF-B8EE-00608CC9A71F),
      helpstring("SourceSafe database object interface"),
      dual,
      oleautomation
    ]
    interface IVSSDatabaseOld : IDispatch {
        [id(0x00000001)]
        HRESULT Open(
                        [in, optional, defaultvalue("")] BSTR SrcSafeIni, 
                        [in, optional, defaultvalue("")] BSTR Username, 
                        [in, optional, defaultvalue("")] BSTR Password);
        [id(0x00000002), propget]
        HRESULT SrcSafeIni([out, retval] BSTR* pSrcSafeIni);
        [id(0x00000003), propget]
        HRESULT DatabaseName([out, retval] BSTR* pDatabaseName);
        [id(0x00000004), propget]
        HRESULT Username([out, retval] BSTR* pUsername);
        [id(0x00000005), propget]
        HRESULT CurrentProject([out, retval] BSTR* pPrj);
        [id(0x00000005), propput]
        HRESULT CurrentProject([in] BSTR pPrj);
        [id(0x00000006), propget]
        HRESULT VSSItem(
                        [in] BSTR Spec, 
                        [in, optional, defaultvalue(0)] VARIANT_BOOL Deleted, 
                        [out, retval] IVSSItem** ppIVSSItem);
    };

    [
      odl,
      uuid(2A0DE0E2-2E9F-11D0-9236-00AA00A1EB95),
      helpstring("SourceSafe database object interface"),
      dual,
      oleautomation
    ]
    interface IVSSDatabaseOld1 : IVSSDatabaseOld {
        [id(0x00000007)]
        HRESULT AddUser(
                        [in] BSTR User, 
                        [in] BSTR Password, 
                        [in] VARIANT_BOOL ReadOnly, 
                        [out, retval] IVSSUser** ppIUser);
        [id(0x00000008), propget]
        HRESULT User(
                        [in] BSTR Name, 
                        [out, retval] IVSSUser** ppIUser);
        [id(0x00000009), propget]
        HRESULT Users([out, retval] IVSSUsers** ppIUsers);
        [id(0x0000000a), propget]
        HRESULT ProjectRightsEnabled([out, retval] VARIANT_BOOL* pEnabled);
        [id(0x0000000a), propput]
        HRESULT ProjectRightsEnabled([in] VARIANT_BOOL pEnabled);
        [id(0x0000000b), propget]
        HRESULT DefaultProjectRights([out, retval] long* pRights);
        [id(0x0000000b), propput]
        HRESULT DefaultProjectRights([in] long pRights);
    };

    [
      odl,
      uuid(2A0DE0EE-2E9F-11D0-9236-00AA00A1EB95),
      helpstring("SourceSafe database object interface"),
      dual,
      oleautomation
    ]
    interface IVSSDatabase : IVSSDatabaseOld1 {
        [id(0x0000000c)]
        HRESULT GetSetting(
                        [in] BSTR Setting, 
                        [out, retval] BSTR* pValue);
        [id(0x0000000d)]
        HRESULT Close();
        [id(0x0000000e), propget]
        HRESULT ImpersonateCaller([out, retval] VARIANT_BOOL* pImpersonate);
        [id(0x0000000e), propput]
        HRESULT ImpersonateCaller([in] VARIANT_BOOL pImpersonate);
    };

    [
      odl,
      uuid(2A0DE0E3-2E9F-11D0-9236-00AA00A1EB95),
      helpstring("SourceSafe user object interface"),
      dual,
      oleautomation
    ]
    interface IVSSUser : IDispatch {
        [id(0x00000001)]
        HRESULT Delete();
        [id(0x00000002), propget]
        HRESULT Name([out, retval] BSTR* pName);
        [id(0x00000002), propput]
        HRESULT Name([in] BSTR pName);
        [id(0x00000003), propput]
        HRESULT Password([in] BSTR rhs);
        [id(0x00000004), propget]
        HRESULT ReadOnly([out, retval] VARIANT_BOOL* pReadOnly);
        [id(0x00000004), propput]
        HRESULT ReadOnly([in] VARIANT_BOOL pReadOnly);
        [id(0x00000005), propget]
        HRESULT ProjectRights(
                        [in, optional, defaultvalue("$/")] BSTR Project, 
                        [out, retval] long* piRightsOut);
        [id(0x00000005), propput]
        HRESULT ProjectRights(
                        [in, optional, defaultvalue("$/")] BSTR Project, 
                        [in] long piRightsOut);
        [id(0x00000006)]
        HRESULT RemoveProjectRights([in] BSTR Project);
    };

    [
      odl,
      uuid(2A0DE0E4-2E9F-11D0-9236-00AA00A1EB95),
      helpstring("SourceSafe users collection interface"),
      dual,
      oleautomation
    ]
    interface IVSSUsers : IDispatch {
        [id(0x00000001), propget]
        HRESULT Count([out, retval] long* piCount);
        [id(00000000), propget]
        HRESULT Item(
                        [in] VARIANT sItem, 
                        [out, retval] IVSSUser** ppIUser);
        [id(0xfffffffc), restricted, hidden]
        HRESULT _NewEnum([out, retval] IUnknown** ppIEnum);
    };

    [
      uuid(783CD4E3-9D54-11CF-B8EE-00608CC9A71F),
      noncreatable
    ]
    coclass VSSItem {
        [default] interface IVSSItem;
        interface IVSSItemOld1;
        interface IVSSItemOld;
    };

    [
      uuid(783CD4EC-9D54-11CF-B8EE-00608CC9A71F),
      noncreatable
    ]
    coclass VSSVersion {
        [default] interface IVSSVersion;
        interface IVSSVersionOld;
    };

    [
      uuid(2A0DE0E0-2E9F-11D0-9236-00AA00A1EB95),
      noncreatable
    ]
    coclass VSSCheckout {
        [default] interface IVSSCheckout;
        interface IVSSCheckoutOld;
    };

    [
      uuid(783CD4E4-9D54-11CF-B8EE-00608CC9A71F)
    ]
    coclass VSSDatabase {
        [default] interface IVSSDatabase;
        interface IVSSDatabaseOld1;
        interface IVSSDatabaseOld;
    };

    [
      uuid(2A0DE0E5-2E9F-11D0-9236-00AA00A1EB95),
      noncreatable
    ]
    coclass VSSUser {
        [default] interface IVSSUser;
    };

    [
      odl,
      uuid(783CD4E9-9D54-11CF-B8EE-00608CC9A71F),
      helpstring("SourceSafe event interface")
    ]
    interface IVSSEventsOld : IUnknown {
        HRESULT _stdcall BeforeAdd(
                        [in] IVSSItem* pIPrj, 
                        [in] BSTR Local, 
                        [out, retval] VARIANT_BOOL* pbContinue);
        HRESULT _stdcall AfterAdd(
                        [in] IVSSItem* pIItem, 
                        [in] BSTR Local);
        HRESULT _stdcall BeforeCheckout(
                        [in] IVSSItem* pIItem, 
                        [in] BSTR Local, 
                        [out, retval] VARIANT_BOOL* pbContinue);
        HRESULT _stdcall AfterCheckout(
                        [in] IVSSItem* pIItem, 
                        [in] BSTR Local);
        HRESULT _stdcall BeforeCheckin(
                        [in] IVSSItem* pIItem, 
                        [in] BSTR Local, 
                        [out, retval] VARIANT_BOOL* pbContinue);
        HRESULT _stdcall AfterCheckin(
                        [in] IVSSItem* pIItem, 
                        [in] BSTR Local);
        HRESULT _stdcall BeforeUndoCheckout(
                        [in] IVSSItem* pIItem, 
                        [in] BSTR Local, 
                        [out, retval] VARIANT_BOOL* pbContinue);
        HRESULT _stdcall AfterUndoCheckout(
                        [in] IVSSItem* pIItem, 
                        [in] BSTR Local);
        HRESULT _stdcall BeforeRename(
                        [in] IVSSItem* pIItem, 
                        [in] BSTR NewName, 
                        [out, retval] VARIANT_BOOL* pbContinue);
        HRESULT _stdcall AfterRename(
                        [in] IVSSItem* pIItem, 
                        [in] BSTR OldName);
        HRESULT _stdcall BeforeBranch(
                        [in] IVSSItem* pIItem, 
                        [out, retval] VARIANT_BOOL* pbContinue);
        HRESULT _stdcall AfterBranch([in] IVSSItem* pIItem);
        HRESULT _stdcall BeforeEvent(
                        [in] long iEvent, 
                        [in] IVSSItem* pIItem, 
                        [in] BSTR Str, 
                        [in] VARIANT var, 
                        [out, retval] VARIANT_BOOL* pbContinue);
        HRESULT _stdcall AfterEvent(
                        [in] long iEvent, 
                        [in] IVSSItem* pIItem, 
                        [in] BSTR Str, 
                        [in] VARIANT var);
    };

    [
      odl,
      uuid(2A0DE0E8-2E9F-11D0-9236-00AA00A1EB95),
      helpstring("SourceSafe event interface")
    ]
    interface IVSSEvents : IUnknown {
        HRESULT _stdcall BeforeAdd(
                        [in] IVSSItem* pIPrj, 
                        [in] BSTR Local, 
                        [in] BSTR Comment, 
                        [out, retval] VARIANT_BOOL* pbContinue);
        HRESULT _stdcall AfterAdd(
                        [in] IVSSItem* pIItem, 
                        [in] BSTR Local, 
                        [in] BSTR Comment);
        HRESULT _stdcall BeforeCheckout(
                        [in] IVSSItem* pIItem, 
                        [in] BSTR Local, 
                        [in] BSTR Comment, 
                        [out, retval] VARIANT_BOOL* pbContinue);
        HRESULT _stdcall AfterCheckout(
                        [in] IVSSItem* pIItem, 
                        [in] BSTR Local, 
                        [in] BSTR Comment);
        HRESULT _stdcall BeforeCheckin(
                        [in] IVSSItem* pIItem, 
                        [in] BSTR Local, 
                        [in] BSTR Comment, 
                        [out, retval] VARIANT_BOOL* pbContinue);
        HRESULT _stdcall AfterCheckin(
                        [in] IVSSItem* pIItem, 
                        [in] BSTR Local, 
                        [in] BSTR Comment);
        HRESULT _stdcall BeforeUndoCheckout(
                        [in] IVSSItem* pIItem, 
                        [in] BSTR Local, 
                        [out, retval] VARIANT_BOOL* pbContinue);
        HRESULT _stdcall AfterUndoCheckout(
                        [in] IVSSItem* pIItem, 
                        [in] BSTR Local);
        HRESULT _stdcall BeforeRename(
                        [in] IVSSItem* pIItem, 
                        [in] BSTR NewName, 
                        [out, retval] VARIANT_BOOL* pbContinue);
        HRESULT _stdcall AfterRename(
                        [in] IVSSItem* pIItem, 
                        [in] BSTR OldName);
        HRESULT _stdcall BeforeBranch(
                        [in] IVSSItem* pIItem, 
                        [in] BSTR Comment, 
                        [out, retval] VARIANT_BOOL* pbContinue);
        HRESULT _stdcall AfterBranch(
                        [in] IVSSItem* pIItem, 
                        [in] BSTR Comment);
        HRESULT _stdcall BeginCommand(
                        [in] long unused, 
                        [out, retval] VARIANT_BOOL* pbContinue);
        HRESULT _stdcall EndCommand([in] long unused);
        HRESULT _stdcall BeforeEvent(
                        [in] long iEvent, 
                        [in] IVSSItem* pIItem, 
                        [in] BSTR Str, 
                        [in] VARIANT var, 
                        [out, retval] VARIANT_BOOL* pbContinue);
        HRESULT _stdcall AfterEvent(
                        [in] long iEvent, 
                        [in] IVSSItem* pIItem, 
                        [in] BSTR Str, 
                        [in] VARIANT var);
    };

    [
      odl,
      uuid(783CD4EB-9D54-11CF-B8EE-00608CC9A71F),
      helpstring("SourceSafe application interface"),
      dual,
      oleautomation
    ]
    interface IVSS : IDispatch {
        [id(0x00000001), propget]
        HRESULT VSSDatabase([out, retval] IVSSDatabase** ppIVSSDatabase);
    };

    [
      odl,
      uuid(783CD4EA-9D54-11CF-B8EE-00608CC9A71F),
      helpstring("SourceSafe event interface")
    ]
    interface IVSSEventHandler : IUnknown {
        HRESULT _stdcall Init([in] IVSS* pIVSS);
    };

    [
      uuid(2A0DE0E1-2E9F-11D0-9236-00AA00A1EB95),
      noncreatable
    ]
    coclass VSSApp {
        [default] interface IVSS;
        [default, source] interface IVSSEvents;
        [source] interface IVSSEventsOld;
    };
};

*/