// calDlg.cpp : implementation file
//

#include "stdafx.h"
#include "cal.h"
#include "calDlg.h"

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
	//{{AFX_MSG(CAboutDlg)
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
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalDlg dialog

CCalDlg::CCalDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCalDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCalDlg)
	m_strResult = _T("");

	//================添加初始化

	m_dNum1=0;
	m_dNum2=0;
	m_chOp='=';
	m_IsFirstNum=TRUE;
	m_division=TRUE;

	//================
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	
	
}

void CCalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCalDlg)
	DDX_Text(pDX, IDC_EDIT1, m_strResult);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCalDlg, CDialog)
	//{{AFX_MSG_MAP(CCalDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN1, OnClickBtn1)
	ON_BN_CLICKED(IDC_BTN2, OnClickBtn2)
	ON_BN_CLICKED(IDC_BTN3, OnClikBtn3)
	ON_BN_CLICKED(IDC_BTN4, OnClickBtn4)
	ON_BN_CLICKED(IDC_BTN5, OnClickBtn5)
	ON_BN_CLICKED(IDC_BTN6, OnClickBtn6)
	ON_BN_CLICKED(IDC_BTN7, OnClickBtn7)
	ON_BN_CLICKED(IDC_BTN8, OnClickBtn8)
	ON_BN_CLICKED(IDC_BTN9, OnClickBtn9)
	ON_BN_CLICKED(IDC_BTN0, OnClickBtn0)
	ON_BN_CLICKED(IDC_BTN_back, OnClickBTNback)
	ON_BN_CLICKED(IDC_BTN_C, OnClickBtnC)
	ON_BN_CLICKED(IDC_BTN_Add, OnClicBTNAdd)
	ON_BN_CLICKED(IDC_BTN_minu, OnClickBTNminu)
	ON_BN_CLICKED(IDC_BTN_Mul, OnClickBTNMul)
	ON_BN_CLICKED(IDC_BTN_Div, OnClickBTNDiv)
	ON_BN_CLICKED(IDC_BTN_Equal, OnClickBTNEqual)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalDlg message handlers

BOOL CCalDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCalDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalDlg::OnPaint() 
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
HCURSOR CCalDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCalDlg::OnClickBtn1() 
{
	// TODO: Add your control notification handler code here

/*	UpdateData(TRUE);
    
	m_strResult=m_strResult+"1";

    //m_numResult=strtod(m_strResult,NULL);

	//m_numResult=m_numResult*2;

    m_strResult.Format("%f",m_numResult);



	UpdateData(FALSE);
*/		

		FunClickNum("1");

}

void CCalDlg::OnClickBtn2() 
{
	// TODO: Add your control notification handler code here
	FunClickNum("2");
}

void CCalDlg::OnClikBtn3() 
{
	// TODO: Add your control notification handler code here
	FunClickNum("3");
	
}

void CCalDlg::OnClickBtn4() 
{
	// TODO: Add your control notification handler code here
		FunClickNum("4");
	
}

void CCalDlg::OnClickBtn5() 
{
	// TODO: Add your control notification handler code here
	FunClickNum("5");
	
}

void CCalDlg::OnClickBtn6() 
{
	// TODO: Add your control notification handler code here
	FunClickNum("6");
	
}

void CCalDlg::OnClickBtn7() 
{
	// TODO: Add your control notification handler code here
	FunClickNum("7");
	
}

void CCalDlg::OnClickBtn8() 
{
	// TODO: Add your control notification handler code here
	FunClickNum("8");
	
}

void CCalDlg::OnClickBtn9() 
{
	// TODO: Add your control notification handler code here
	FunClickNum("9");
	
}

void CCalDlg::OnClickBtn0() 
{
	// TODO: Add your control notification handler code here
	FunClickNum("0");
	
}

void CCalDlg::OnClickBTNback() 
{
	// TODO: Add your control notification handler code here
		UpdateData(TRUE);


	m_strResult=m_strResult.Left(m_strResult.GetLength()-1);//删除字符串最后一个数


 	UpdateData(FALSE);

	
}

void CCalDlg::OnClickBtnC() 
{
	// TODO: Add your control notification handler code here

	//================添加初始化

	m_dNum1=0;
	m_dNum2=0;
	m_chOp='=';
	m_IsFirstNum=TRUE;
	FunClickNum("");
	m_division=TRUE;

	//================
	
}

void CCalDlg::OnClicBTNAdd() 
{
	// TODO: Add your control notification handler code here

	FunClickChOp(m_chOp);	
	m_chOp='+';
	
}

void CCalDlg::OnClickBTNminu() 
{
	// TODO: Add your control notification handler code here
	FunClickChOp(m_chOp);	
	m_chOp='-';
}

void CCalDlg::OnClickBTNMul() 
{
	// TODO: Add your control notification handler code here
	FunClickChOp(m_chOp);	
	m_chOp='*';
}

void CCalDlg::OnClickBTNDiv() 
{
	// TODO: Add your control notification handler code here
	FunClickChOp(m_chOp);	
	m_chOp='/';	
}

void CCalDlg::OnClickBTNEqual() 
{
	// TODO: Add your control notification handler code here
	FunClickChOp(m_chOp);	
	m_chOp='=';
	
}

void  CCalDlg::FunClickNum (const char *strNum)
{ 

	UpdateData(TRUE);

	if (m_IsFirstNum)

	{ m_strResult=_T("");
	  m_IsFirstNum=FALSE;
	}
    
	m_strResult=m_strResult+strNum;


 	UpdateData(FALSE);
}

void  CCalDlg::FunClickChOp (char Chop)
{ 

	UpdateData(TRUE);

	m_dNum1=atof(m_strResult); //将字符串转换成数字

	switch(Chop)
	{ case '+': m_dNum2=m_dNum2+m_dNum1;   break;//进行加法计算
	  case '-': m_dNum2=m_dNum2-m_dNum1;   break;//进行减法计算
	  case '*': m_dNum2=m_dNum2*m_dNum1;   break;//进行乘法计算
	  case '/': 
	    if (fabs(m_dNum1-0)>1e-12) 
			  m_dNum2=m_dNum2/m_dNum1;
		  else
		  { m_strResult="Error division,clear with c";
		    
	        UpdateData(FALSE);

			m_division=FALSE; //判断是否是合法的除法的指标

		  }
		    
		   break;//进行除法计算，需要判断第二个数是否是零



	  case '=':
		  m_dNum2=m_dNum1; 
	}

	if (m_division)
	
	{m_strResult.Format("%lf",m_dNum2);//将数字转换成字符串
    m_IsFirstNum=TRUE;//点击加号以后需要将标志恢复
	UpdateData(FALSE);
	}

}