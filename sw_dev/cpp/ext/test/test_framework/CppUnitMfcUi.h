// CppUnitMfcUi.h : main header file for the CPPUNITMFCUI application
//

#if !defined(AFX_CPPUNITMFCUI_H__37F928CC_24F9_4D0D_B88A_112093DA15B8__INCLUDED_)
#define AFX_CPPUNITMFCUI_H__37F928CC_24F9_4D0D_B88A_112093DA15B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCppUnitMfcUiApp:
// See CppUnitMfcUi.cpp for the implementation of this class
//

class CCppUnitMfcUiApp : public CWinApp
{
public:
	CCppUnitMfcUiApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCppUnitMfcUiApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCppUnitMfcUiApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CPPUNITMFCUI_H__37F928CC_24F9_4D0D_B88A_112093DA15B8__INCLUDED_)