// LottryPlanDlg.h : header file
//

#if !defined(AFX_LOTTRYPLANDLG_H__B4B37BEC_C043_4F72_B9D3_956D449FAB32__INCLUDED_)
#define AFX_LOTTRYPLANDLG_H__B4B37BEC_C043_4F72_B9D3_956D449FAB32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\Share\SortListCtrl.h"
#include "..\Share\HyperLink.h"

//#define for if(0); else for
#define for if(1) for
#define MAX_COL_WIDTH 20

/////////////////////////////////////////////////////////////////////////////
// CLottryPlanDlg dialog

class CLottryPlanDlg : public CDialog
{
// Construction
public:
	void ChgState();
	CLottryPlanDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLottryPlanDlg)
	enum { IDD = IDD_LOTTRYPLAN_DIALOG };
	CSortListCtrl	m_lstResult;
	UINT	m_nPeriod;
	UINT	m_nRecord;
	UINT	m_nMult;
	DWORD	m_nBonus;
	UINT	m_nYield;
	double	m_fPercent;
	double	m_fPickup;
	int		m_iPickPer;
	UINT	m_nIncome;
	int		m_nRad;
	UINT	m_nChg;
	BOOL	m_bEnsure;
	BOOL	m_bSwt;
	UINT	m_nCond2;
	DWORD	m_dwMaxMuti;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLottryPlanDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	
	// Generated message map functions
	//{{AFX_MSG(CLottryPlanDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnCalc();
	afx_msg void OnSave();
	afx_msg void OnAbout();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnCheckSwitch();
	afx_msg void OnCheck1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOTTRYPLANDLG_H__B4B37BEC_C043_4F72_B9D3_956D449FAB32__INCLUDED_)
