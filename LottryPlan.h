// LottryPlan.h : main header file for the LOTTRYPLAN application
//

#if !defined(AFX_LOTTRYPLAN_H__36D8F063_0B11_47BF_8288_6463B27DBE27__INCLUDED_)
#define AFX_LOTTRYPLAN_H__36D8F063_0B11_47BF_8288_6463B27DBE27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLottryPlanApp:
// See LottryPlan.cpp for the implementation of this class
//

class CLottryPlanApp : public CWinApp
{
public:
	CLottryPlanApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLottryPlanApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLottryPlanApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
		
	HANDLE m_hMutex;
	
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOTTRYPLAN_H__36D8F063_0B11_47BF_8288_6463B27DBE27__INCLUDED_)
