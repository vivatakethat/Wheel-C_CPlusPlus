// calDlg.h : header file
//

#if !defined(AFX_CALDLG_H__3AD6BD63_D891_4EBA_A167_2C6AB5B3A784__INCLUDED_)
#define AFX_CALDLG_H__3AD6BD63_D891_4EBA_A167_2C6AB5B3A784__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCalDlg dialog

class CCalDlg : public CDialog
{
// Construction
public:
	CCalDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCalDlg)
	enum { IDD = IDD_CAL_DIALOG };
	CString	m_strResult;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCalDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCalDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClickBtn1();
	afx_msg void OnClickBtn2();
	afx_msg void OnClikBtn3();
	afx_msg void OnClickBtn4();
	afx_msg void OnClickBtn5();
	afx_msg void OnClickBtn6();
	afx_msg void OnClickBtn7();
	afx_msg void OnClickBtn8();
	afx_msg void OnClickBtn9();
	afx_msg void OnClickBtn0();
	afx_msg void OnClickBTNback();
	afx_msg void OnClickBtnC();
	afx_msg void OnClicBTNAdd();
	afx_msg void OnClickBTNminu();
	afx_msg void OnClickBTNMul();
	afx_msg void OnClickBTNDiv();
	afx_msg void OnClickBTNEqual();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private: 
   void FunClickNum (const char *strNum);
   double m_dNum1,m_dNum2;
   bool m_IsFirstNum;
   char m_chOp;
   void FunClickChOp (char chOp);
   bool m_division;




};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALDLG_H__3AD6BD63_D891_4EBA_A167_2C6AB5B3A784__INCLUDED_)
