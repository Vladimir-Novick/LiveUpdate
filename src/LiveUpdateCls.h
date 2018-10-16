// LiveUpdateCls.h: interface for the CLiveUpdateCls class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LIVEUPDATECLS_H__2C3D7E3E_1086_40FA_8CDA_C85EBD4BF570__INCLUDED_)
#define AFX_LIVEUPDATECLS_H__2C3D7E3E_1086_40FA_8CDA_C85EBD4BF570__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CLiveUpdateCls1  
{
public:
	BOOL LiveGetInternetFile(HWND hwnd, char *URL, char *strLocalFileName);
	CLiveUpdateCls(){};
	~CLiveUpdateCls(){};


};

#endif // !defined(AFX_LIVEUPDATECLS_H__2C3D7E3E_1086_40FA_8CDA_C85EBD4BF570__INCLUDED_)
