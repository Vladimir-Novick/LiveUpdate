// MyLiveUpdate.cpp: implementation of the MyLiveUpdate class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyLiveUpdate.h"
#include "Wininet.h"


bool GoLiveUpdate(HWND hwnd, char *URL, char *strLocalFileName){
 MyLiveUpdate m_MyLiveUpdate;
 return m_MyLiveUpdate.LiveGetInternetFile(hwnd, URL, strLocalFileName);
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MyLiveUpdate::MyLiveUpdate()
{

}

MyLiveUpdate::~MyLiveUpdate()
{

}

bool MyLiveUpdate::LiveGetInternetFile(HWND hwnd, char *URL, char *strLocalFileName)
{
 BOOL bReturn = FALSE;

  HINTERNET hOpen = NULL, 
            hConnect = NULL, 
            hRequest = NULL;

  DWORD dwSize = 0, 
        dwFlags = INTERNET_FLAG_RELOAD | INTERNET_FLAG_NO_CACHE_WRITE; 

  TCHAR szErrMsg[200];
  
  char *lpBufferA,
       *lpHeadersA;

  TCHAR *lpBufferW,
        *lpHeadersW;

  LPTSTR AcceptTypes[2] = {TEXT("*/*"), NULL}; 

 

    hOpen = InternetOpen (TEXT("EDictionary 4.0 Live Update"), INTERNET_OPEN_TYPE_PRECONFIG,
                          NULL, 0, 0);


  if (!hOpen)
  {
    wsprintf (szErrMsg, TEXT("%s: %x"), TEXT("Internet Open Error"), 
              GetLastError());
   SetWindowText(hwnd,szErrMsg);
    return FALSE;
  }
  

    if (!(hRequest = InternetOpenUrl (hOpen, URL, NULL, 0, 
                                      INTERNET_FLAG_RELOAD, 0)))
    {
      wsprintf (szErrMsg, TEXT("%s: %x"), TEXT("Invalid update information"),
                GetLastError());
      SetWindowText(hwnd,szErrMsg);
      goto exit;
    }
 


  
  // Call HttpQueryInfo to find out the size of the headers.
  HttpQueryInfo (hRequest, HTTP_QUERY_RAW_HEADERS_CRLF, NULL, &dwSize,
                 NULL);

  // Allocate a block of memory for lpHeadersA.
  lpHeadersA = new CHAR [dwSize];

  // Call HttpQueryInfo again to get the headers.
  if (!HttpQueryInfo (hRequest, 
                      HTTP_QUERY_RAW_HEADERS_CRLF, 
                      (LPVOID) lpHeadersA, &dwSize, NULL))
  {
    wsprintf (szErrMsg, TEXT("%s: %x"), TEXT("HttpQueryInfo"), 
              GetLastError());
    goto exit;
  }
  else
  {

  }



  // Allocate a block of memory for lpHeadersW.
  lpBufferA = new CHAR [32000];

   HANDLE hFreshFile;
   unsigned long iBytesWritten;
   hFreshFile = CreateFile(strLocalFileName, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ |
    FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL );



  do
  {
    if (!InternetReadFile (hRequest, (LPVOID)lpBufferA, 32000, &dwSize))
    {
      wsprintf(szErrMsg, TEXT("%s: %x"), TEXT("InternetReadFile Error"), 
               GetLastError());
      goto exit;
    }

    if (dwSize != 0)    
    {

      WriteFile(hFreshFile,lpBufferA,dwSize,&iBytesWritten,NULL);

    }    
  } while (dwSize);

   CloseHandle(hFreshFile);


  // Free the block of memory.
  delete[] lpBufferA;  

  bReturn = TRUE;

exit:



  // Close the Internet handles.
  if (hOpen)
  {
    if (!InternetCloseHandle (hOpen))
      wsprintf (szErrMsg, TEXT("%s: %x"), TEXT("Internet Close Error"), 
                GetLastError());
  }
  

  if (hRequest)
  {
    if (!InternetCloseHandle (hRequest))
      wsprintf (szErrMsg, TEXT("%s: %x"), TEXT("Internet Close Error"), 
                GetLastError());
  }

  SetWindowText(hwnd,szErrMsg);

  return bReturn;


}
