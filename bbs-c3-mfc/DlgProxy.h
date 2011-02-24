// DlgProxy.h: header file
//

#pragma once

class Cbbsc3mfcDlg;


// Cbbsc3mfcDlgAutoProxy command target

class Cbbsc3mfcDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(Cbbsc3mfcDlgAutoProxy)

	Cbbsc3mfcDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	Cbbsc3mfcDlg* m_pDialog;

// Operations
public:

// Overrides
	public:
	virtual void OnFinalRelease();

// Implementation
protected:
	virtual ~Cbbsc3mfcDlgAutoProxy();

	// Generated message map functions

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(Cbbsc3mfcDlgAutoProxy)

	// Generated OLE dispatch map functions

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

