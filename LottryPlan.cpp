// LottryPlan.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "LottryPlan.h"
#include "LottryPlanDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLottryPlanApp

BEGIN_MESSAGE_MAP(CLottryPlanApp, CWinApp)
	//{{AFX_MSG_MAP(CLottryPlanApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLottryPlanApp construction

CLottryPlanApp::CLottryPlanApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CLottryPlanApp object

CLottryPlanApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CLottryPlanApp initialization

BOOL CLottryPlanApp::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif
	// �ж��Ƿ���һ��ΪstrClassName��mutex����
    CString	strClassName;
	strClassName.LoadString(IDS_CLASS_NAME);
	
	m_hMutex = OpenMutex (MUTEX_ALL_ACCESS, FALSE, strClassName) ;
	if (m_hMutex == NULL)
	{
		// m_hMutex�����ڣ���ʾû������ʵ�������У�����һ��m_hMutex
		m_hMutex = CreateMutex(NULL, TRUE, strClassName) ;
	}
	else if(ERROR_ALREADY_EXISTS == ::GetLastError())
	{
		AfxMessageBox(_T("�ϴγ���δ�����˳�!"));
	}
	else
	{
		// ���m_hMutex���ڣ���ʾ�Ѿ���һ��ʵ�������У�
		// ���������ĳ��򴴽���һ����ΪstrClassName��m_hMutex
		
		// ����ʵ���ᵽǰ̨
//		strClassName.LoadString(IDS_TITLE);
//		::ActiveWindow(strClassName);
	
		// ������ʵ������
		return FALSE;
	}
	
	CLottryPlanDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

int CLottryPlanApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class

	if(m_hMutex != NULL)
	{
		ReleaseMutex(m_hMutex);
	}
	
	return CWinApp::ExitInstance();
}
