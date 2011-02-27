// bbs-c3-mfcDlg.h : header file
//

#pragma once
#include "worker.h"
#include "afxwin.h"
class Cbbsc3mfcDlgAutoProxy;


// Cbbsc3mfcDlg dialog
class Cbbsc3mfcDlg : public CDialog
{
	DECLARE_DYNAMIC(Cbbsc3mfcDlg);
	friend class Cbbsc3mfcDlgAutoProxy;

// Construction
public:
	Cbbsc3mfcDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~Cbbsc3mfcDlg();

// Dialog Data
	enum { IDD = IDD_BBSC3MFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	Cbbsc3mfcDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()

	CWorker work;

	void CheckField();

public:
	CString firstStart;
	CString firstEnd;
	CString secondStart;
	CString secondEnd;
	CString fileName;
	afx_msg void OnBnClickedBrowse();
	CEdit _firstStartCtrl;
	CButton _startBtn;
	afx_msg void OnBnClickedStart();
};
