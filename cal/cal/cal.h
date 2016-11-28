// cal.h : main header file for the CAL application
//

#if !defined(AFX_CAL_H__8D9A03DC_5F2E_48DF_AFB3_E709E6B7EA37__INCLUDED_)
#define AFX_CAL_H__8D9A03DC_5F2E_48DF_AFB3_E709E6B7EA37__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCalApp:
// See cal.cpp for the implementation of this class
//

class CCalApp : public CWinApp
{
public:
	CCalApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCalApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCalApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAL_H__8D9A03DC_5F2E_48DF_AFB3_E709E6B7EA37__INCLUDED_)
