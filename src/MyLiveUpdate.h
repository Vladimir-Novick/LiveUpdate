// MyLiveUpdate.h: interface for the MyLiveUpdate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYLIVEUPDATE_H__14FFDBDF_776A_48E3_933C_F6A0C14760B0__INCLUDED_)
#define AFX_MYLIVEUPDATE_H__14FFDBDF_776A_48E3_933C_F6A0C14760B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

bool GoLiveUpdate(HWND hwnd, char *URL, char *strLocalFileName);

class MyLiveUpdate  
{
public:
	bool LiveGetInternetFile(HWND hwnd, char *URL, char *strLocalFileName);
	MyLiveUpdate();
	virtual ~MyLiveUpdate();

};

#endif // !defined(AFX_MYLIVEUPDATE_H__14FFDBDF_776A_48E3_933C_F6A0C14760B0__INCLUDED_)
