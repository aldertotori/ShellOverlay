/*
SRComHelper is a class designed to facilitate calling invoke for various COM abjects. 
You may use and distribute this class freely.  
Any suggestions for improving the code can be sent to rbanerji666@yahoo.com
Authors:		Ranjan Banerji
				Estelle Mangeney
Last Updated:	03/01/2001
				02/04/2002
*/

#include "StdAfx.h"
#include "SRComHelper.h"


/************************************************************
Error Codes
************************************************************/
#define CLSIDFromProgID_Failed	-1
#define CreateInstance_Failed	-2	
#define ExtraArg_AddToArray_Failed	-3

CSRComHelper::CSRComHelper() : _safeArray(NULL), _count(0)
{
}

HRESULT CSRComHelper::Create(const CComBSTR& strclsid )
{
	CLSID clsid;
	HRESULT result = CLSIDFromString( strclsid, &clsid );
	if( SUCCEEDED( result ) ) {
		result = _disp.CreateInstance(clsid);
		if( !SUCCEEDED( result ) )
			result = CreateInstance_Failed;
	}
	else
		result = CLSIDFromProgID_Failed;
	return result;
}

CSRComHelper::~CSRComHelper() {
	Reset();
}

void CSRComHelper::Reset() {
	if( _safeArray != NULL ) {
		SafeArrayDestroy(_safeArray);
		_safeArray = NULL;
	}
	if( NULL != _rgvarg ) {
		delete[] _rgvarg;
		_rgvarg = NULL;
	}
	_count = 0;
}

void CSRComHelper::CreateArray( const int& cElements ) {
	SAFEARRAYBOUND rgsabound[1];
	rgsabound[0].lLbound = 0; 
	rgsabound[0].cElements = cElements;
	_safeArray = SafeArrayCreate( VT_VARIANT, 1, rgsabound );
	_maxSize = cElements;
}

void CSRComHelper::AddIntoArray( VARIANT& argument ) {
	if( _count < _maxSize ) {
		long index = _count;
		SafeArrayPutElement( _safeArray, &index, &argument );
		_count++;
	}
	else {
		throw (int)ExtraArg_AddToArray_Failed;
	}
}

void CSRComHelper::SetParam( const int& argument ) {
	VARIANT param;

	param.vt = VT_I2;
	param.intVal = argument;
	AddIntoArray(param);
}

void CSRComHelper::SetParam( int* argument ) {
	VARIANT param;

	param.vt = VT_I2| VT_BYREF;
	param.pintVal = argument;
	AddIntoArray(param);
}

void CSRComHelper::SetParam( const long& argument ) {
	VARIANT param;

	param.vt = VT_I4;
	param.lVal = argument;
	AddIntoArray(param);
}

void CSRComHelper::SetParam( long* argument ) {
	VARIANT param;

	param.vt = VT_I4 | VT_BYREF;
	param.plVal = argument;
	AddIntoArray(param);
}

void CSRComHelper::SetParam( const CComBSTR& argument ) {
	VARIANT param;

	param.vt = VT_BSTR;
	param.bstrVal = argument;
	AddIntoArray(param);
}

void CSRComHelper::SetParam( const CComBSTR* argument ) {
	VARIANT param;
	BSTR argConversion;

	argConversion = argument->Copy();
	param.vt = VT_BSTR | VT_BYREF;
	param.pbstrVal = &argConversion;
	AddIntoArray(param);
}

void CSRComHelper::SetParam( SAFEARRAY* argument ) {
	VARIANT param;

	param.vt = VT_ARRAY | VT_VARIANT;
	param.parray = argument;
	AddIntoArray(param);
}

void CSRComHelper::SetParam( VARIANT& argument ) {
	VARIANT param;

	param.vt =  VT_VARIANT;
	param.pvarVal = &argument;
	AddIntoArray(param);
}

void CSRComHelper::SetParam( VARIANT* argument ) {
	VARIANT param;

	param.vt =  VT_VARIANT | VT_BYREF;
	param.pvarVal = argument;
	AddIntoArray(param);
}

VARIANT CSRComHelper::GetOutput( const int& position ) {
	VARIANT myVar;
	myVar = _rgvarg[ (_safeArray->rgsabound[0].cElements - 1) - position ];
	return myVar;
}

HRESULT CSRComHelper::CallInvoke( const CComBSTR& fnName, VARIANT& dispRes ) {
	HRESULT hr = S_OK;

	EXCEPINFO *pExcepInfo = NULL;
	unsigned int *puArgErr = NULL;
	int iNbElements;
   	long index;
    DISPPARAMS dispparams;
	dispparams.rgvarg = NULL;
	dispparams.cArgs =0;
	dispparams.cNamedArgs = 0;
	_rgvarg = NULL;

	if( _safeArray != NULL ) { // function takes arguments, NULL otherwise
		iNbElements = _safeArray->rgsabound[0].cElements;
		// Arguments of the function
		_rgvarg = new VARIANT[iNbElements];  //Create an array of VARIANTs
		for ( int i = 0 ; i < iNbElements;i++ ){
			index = i;
			SafeArrayGetElement( _safeArray, &index, &_rgvarg[(iNbElements-1) -i] );
		}
		dispparams.rgvarg = _rgvarg;
		dispparams.cArgs = iNbElements;
		dispparams.cNamedArgs = 0;
	}

	LPOLESTR GetFName[1] = {fnName}; //name of the function to call
	hr = _disp->GetIDsOfNames(IID_NULL, GetFName, 1, LOCALE_SYSTEM_DEFAULT, _functionID);

	try {
		if( SUCCEEDED(hr) ) {
			hr = _disp->Invoke( _functionID[0], IID_NULL, LOCALE_SYSTEM_DEFAULT, DISPATCH_METHOD, 
								&dispparams, &dispRes, pExcepInfo, puArgErr );
		}
	}
	catch(_com_error* e) {
		_bstr_t error = e->Description();
	}
	catch(...) {
		int x = 2;
		x += 3;
	}
	if( puArgErr )
		delete puArgErr;

	return hr;		
}

