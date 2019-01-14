// LottryPlanDlg.cpp : implementation file
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
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
	
// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CHyperLink lnkMail;
	CHyperLink lnkHomepage;
	//{{AFX_MSG(CAboutDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLottryPlanDlg dialog

CLottryPlanDlg::CLottryPlanDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLottryPlanDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLottryPlanDlg)
	m_nPeriod = 10;
	m_nRecord = 10;
	m_nMult = 1;
	m_nBonus = 160;
	m_nYield = 100;
	m_fPercent = 0.0;
	m_fPickup = 0.0;
	m_iPickPer = 5;
	m_nIncome = 100;
	m_nRad = 0;
	m_nChg = 6;
	m_bEnsure = FALSE;
	m_bSwt = FALSE;
	m_nCond2 = 50;
	m_dwMaxMuti = 1000;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
//	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hIcon = AfxGetApp()->LoadIcon(_T("IDI_24"));
}

void CLottryPlanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLottryPlanDlg)
	DDX_Control(pDX, IDC_LIST2, m_lstResult);
	DDX_Text(pDX, IDC_EDIT1, m_nPeriod);
	DDX_Text(pDX, IDC_EDIT2, m_nRecord);
	DDV_MinMaxUInt(pDX, m_nRecord, 1, 1000);
	DDX_Text(pDX, IDC_EDIT3, m_nMult);
	DDV_MinMaxUInt(pDX, m_nMult, 1, 1000);
	DDX_Text(pDX, IDC_EDIT4, m_nBonus);
	DDV_MinMaxDWord(pDX, m_nBonus, 1, 5000000);
	DDX_Text(pDX, IDC_EDIT5, m_nYield);
	DDV_MinMaxUInt(pDX, m_nYield, 1, 10000);
	DDX_Text(pDX, IDC_EDIT6, m_fPercent);
	DDX_Text(pDX, IDC_EDIT7, m_fPickup);
	DDX_Text(pDX, IDC_EDIT8, m_iPickPer);
	DDV_MinMaxInt(pDX, m_iPickPer, 0, 10);
	DDX_Text(pDX, IDC_EDIT9, m_nIncome);
	DDX_Radio(pDX, IDC_RADIO1, m_nRad);
	DDX_Text(pDX, IDC_EDIT10, m_nChg);
	DDV_MinMaxUInt(pDX, m_nChg, 1, 100);
	DDX_Check(pDX, IDC_CHECK1, m_bEnsure);
	DDX_Check(pDX, IDC_CHECK_SWITCH, m_bSwt);
	DDX_Text(pDX, IDC_EDIT11, m_nCond2);
	DDV_MinMaxUInt(pDX, m_nCond2, 1, 10000);
	DDX_Text(pDX, IDC_MAX_MUTI, m_dwMaxMuti);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLottryPlanDlg, CDialog)
	//{{AFX_MSG_MAP(CLottryPlanDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCALC, OnCalc)
	ON_BN_CLICKED(IDSAVE, OnSave)
	ON_BN_CLICKED(IDABOUT, OnAbout)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_CHECK_SWITCH, OnCheckSwitch)
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLottryPlanDlg message handlers

BOOL CLottryPlanDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	CString strTitle;
	strTitle.LoadString(IDS_TITLE);
	SetWindowText(strTitle);
	
	m_lstResult.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_lstResult.SetHeadings( _T("期序, 45;倍投, 45;本期投入, 70;累计投入, 70;本期收益, 70;净收益, 60;收益率, 60;") );
	m_lstResult.LoadColumnInfo();
	
	ChgState();
	UpdateData(FALSE);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLottryPlanDlg::OnOK() 
{
	UpdateData(TRUE);
	m_lstResult.DeleteAllItems();
	
	CString str(_T("")), str1(_T("")), str2(_T("")), str3(_T(""));
	CString str4(_T("")), str5(_T("")), str6(_T(""));
	UINT nPeriod = 1;
	LONG lMult = m_nMult;
	LONG lMoney = 0;
	LONG lMoneyCnt = 0;
	LONG lBonus;
	LONG lIncome;
	DOUBLE fYield = 0.0;

	BOOL bError = FALSE;
	
	do
	{
		if (lMult == (LONG)m_nMult && m_nBonus <= m_nRecord * 2)
		{
			bError = TRUE;
			break;
		}

		LONG lCurAdd = 0;
		do
		{
			lMoney = m_nRecord * 2 * lMult;
			lCurAdd = m_nRecord * 2 * lMult;
			lBonus = m_nBonus * lMult;
			lIncome = lBonus - lMoneyCnt-lCurAdd;
			fYield = lIncome * 100.0 / (lMoneyCnt + lCurAdd);

			if (m_nRad == 0)// && !m_bSwt)
			{
				if (fYield >= (nPeriod < m_nChg || !m_bSwt ? (double)m_nYield : (double)m_nCond2)
					&& (m_bEnsure ? lIncome >= (LONG)m_nIncome : TRUE))
				{
					break;
				}
				else
				{
					++lMult;
				}
			}
			else // (m_nRad == 1)
			{
				BOOL b1 = nPeriod < m_nChg || !m_bSwt;
				LONG t1 = m_bEnsure ? nPeriod : 1;
				LONG l1 = (LONG)m_nIncome;
				LONG l2 = (LONG)m_nCond2;

				if (lIncome >=
					(((LONG)nPeriod < (LONG)m_nChg || !m_bSwt) ? ((LONG)m_nIncome) : ((LONG)m_nCond2))
					* (LONG)(m_bEnsure ? nPeriod : 1)
					)
				{
					break;
				}
				else
				{
					++lMult;
				}
			}

		} while(lMult < (LONG)m_dwMaxMuti);
		lMoneyCnt += lCurAdd;

		// 添加列表项，
		str.Format("  %03d", nPeriod);
		str1.Format(" %d", lMult);
		str2.Format(" %d", lMoney);
		str3.Format(" %d", lMoneyCnt);
		str4.Format(" %d", lBonus);
		str5.Format(" %d", lIncome);
		str6.Format(" %.2f%%", fYield);
		m_lstResult.AddItem(str, str1, str2, str3, str4, str5, str6);

		// 第一列颜色
		m_lstResult.SetItemColor(nPeriod-1, 0, RGB(255, 255, 255), RGB(0, 0, 0));

		// 偶数行背景色
		if (!(nPeriod & 1))
		{
			for(int i=1; i<7; ++i)
			{
				m_lstResult.SetItemColor(nPeriod-1, i, 0, RGB(203, 233, 241));
			}
		}

		// 限倍
		if(bError = (lMult >= (LONG)m_dwMaxMuti))
		{
			break;
		}
		
	} while(++nPeriod <= m_nPeriod);

	if (m_lstResult.GetItemCount() < (int)m_nPeriod)
	{
		MessageBox("投资不现实，此方案不宜倍投!", "提醒");
	}

	// 设置保存按钮状态
	GetDlgItem(IDSAVE)->EnableWindow(!bError);

	// 计算合买信息
	m_fPercent = 0.5 / m_nRecord * m_nBonus * (1.0 - m_iPickPer / 100.0);
	m_fPickup = m_nBonus * m_nMult * m_iPickPer / 100.0;

	UpdateData(FALSE);
}

void CLottryPlanDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLottryPlanDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLottryPlanDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CLottryPlanDlg::OnCalc() 
{
	// TODO: Add your control notification handler code here
	WinExec("CALC.EXE", SW_SHOW);
}

void CLottryPlanDlg::OnSave() 
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(FALSE, "txt");
	dlg.m_ofn.lpstrFilter="文本文件(*.txt)\0*.txt\0所有文件(*.*)\0*.*";
	dlg.m_ofn.hwndOwner = AfxGetMainWnd()->GetSafeHwnd();
	if(dlg.DoModal() == IDCANCEL)
	{
		return;
	}
	
	CString str;
	CString Filename = dlg.GetPathName();
	CStdioFile fo(Filename, CFile::modeCreate | CFile::modeWrite | CFile::typeText );
	
	str.Format("计划期数=%d 每期注数=%d 起投倍数=%d 单倍奖金=%d\n",
		m_nPeriod, m_nRecord, m_nMult, m_nBonus);
	fo.WriteString(str);

	str.Format( "预期收益>=%d%s", (m_nRad==0 ? m_nYield : m_nIncome),
		(m_nRad==0 ? ("%") : (m_bEnsure ? ("元/期") : ("元"))) );

	if (m_bSwt)
	{
		CString str0;
		str0.Format( "，第 %d 期起切换收益条件为 >=%d%s", m_nChg, m_nCond2,
			(m_nRad==0 ? ("%") : (m_bEnsure ? ("元/期") : ("元"))) );
		str += str0;
	}

	str += "\n";
	fo.WriteString(str);

	str = CString("\n期序\t倍数\t本期\t累计\t收益\t净收益\t收益率\n");
	fo.WriteString(str);

	char lpszStr[MAX_COL_WIDTH];
	int cntRow = m_lstResult.GetItemCount();
	for(int i = 0; i < cntRow; ++i)
	{
		str.Empty();
		for(int cntCol = m_lstResult.GetColumns(), j=0; j < cntCol; ++j)
		{
			m_lstResult.GetItemText(i, j, lpszStr, MAX_COL_WIDTH);
			str += CString(lpszStr) + CString("\t");
		}
		str += "\n";
		fo.WriteString(str);
	}

	fo.Close();
	str = "NotePad.EXE " + Filename;
	WinExec(str, SW_SHOW);
}

void CLottryPlanDlg::OnAbout() 
{
	// TODO: Add your control notification handler code here
	CAboutDlg dlg;
	dlg.DoModal();
}

void CLottryPlanDlg::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	m_nRad = 0;
	ChgState();
}

void CLottryPlanDlg::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_nRad = 1;
	m_bEnsure = FALSE;
	UpdateData(FALSE);
	ChgState();
	UpdateData(FALSE);
}

void CLottryPlanDlg::OnCheckSwitch() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	GetDlgItem(IDC_EDIT10)->EnableWindow(m_bSwt);
	GetDlgItem(IDC_EDIT11)->EnableWindow(m_bSwt);
	UpdateData(FALSE);
}

void CLottryPlanDlg::OnCheck1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	GetDlgItem(IDC_EDIT9)->EnableWindow(m_nRad == 1 || m_bEnsure);
	UpdateData(FALSE);
}

void CLottryPlanDlg::ChgState()
{
	UpdateData(TRUE);
	GetDlgItem(IDC_EDIT5)->EnableWindow(m_nRad == 0);
	GetDlgItem(IDC_EDIT9)->EnableWindow(m_nRad == 1 || m_bEnsure);
	GetDlgItem(IDC_EDIT10)->EnableWindow(m_bSwt);
	GetDlgItem(IDC_EDIT11)->EnableWindow(m_bSwt);
	GetDlgItem(IDC_CHECK1)->SetWindowText(m_nRad == 0 ? "全程保证净收益" : "日均净收益");
	GetDlgItem(IDC_STATIC_UNIT)->SetWindowText(m_nRad == 0 ? "%" : "元");
	UpdateData(FALSE);
}

BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	lnkMail.Attach(GetDlgItem(IDC_MAIL)->GetSafeHwnd());
	lnkHomepage.Attach(GetDlgItem(IDC_HOMEPAGE)->GetSafeHwnd());

	lnkMail.SetLink("tuxw2005@gmail.com", "mailto:tuxw2005@gmail.com", TRUE);
	lnkHomepage.SetLink("https://seanto.github.io", "https://seanto.github.io", TRUE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
