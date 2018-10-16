// MainWindow.cpp : Implementation of CMainWindow
#include "stdafx.h"
#include "MainWindow.h"
#include "MyLiveUpdate.h"

/////////////////////////////////////////////////////////////////////////////
// CMainWindow

LRESULT CMainWindow::OnClickedButton_test(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
        GoLiveUpdate(this->m_hWnd , "http:////www.deltacom.co.il//dic//edictionary.zip", "c://edictionary.zip");
		return 0;
	}
