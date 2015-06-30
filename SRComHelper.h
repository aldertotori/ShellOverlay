/*
SRComHelper is a class designed to facilitate calling invoke for various COM abjects.  You may use
and distribute this class freely as long as this header remains.  Any suggestions for
improving the code can be sent to rbanerji666@yahoo.com
Authors:		Ranjan Banerji
				Estelle Mangeney
Last Updated:	03/01/2001
*/

#include <comdef.h>
#include <atlbase.h>


// This class is exported from the SRComHelper.dll
class CSRComHelper {
	
	public:
		CSRComHelper();
		virtual ~CSRComHelper();
		HRESULT Create(const CComBSTR& clsid );
		// TODO: add your methods here.
		/*Functions to set the parameter for invoke*/
		HRESULT CallInvoke( const CComBSTR& ftnName, VARIANT& dispRes );
		/*Tools to generate the Array*/
		void  CreateArray( const int& numItems );
		void AddIntoArray( VARIANT& vtItem );
		/*Create the params*/
		void SetParam( const int& i );
		void SetParam( int* i );
		void SetParam( const long& l );
		void SetParam( long* l );
		void SetParam( const CComBSTR& str );
		void SetParam( const CComBSTR* str );
		void SetParam( SAFEARRAY* array );
		void SetParam( VARIANT& argument );
		void SetParam( VARIANT* var );
// Inspectros
		SAFEARRAY* GetArray() { return _safeArray; } 
		VARIANT GetOutput(const int& position);

		void Reset();
	protected:
		SAFEARRAY*		_safeArray;
		DISPID			_functionID[1];
		VARIANT*		_rgvarg;  
		int				_count;
		int				_maxSize;
		IDispatchPtr	_disp;
};