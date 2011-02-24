// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "bbs-c3-mfc.h"
#include "DlgProxy.h"
#include "bbs-c3-mfcDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cbbsc3mfcDlgAutoProxy

IMPLEMENT_DYNCREATE(Cbbsc3mfcDlgAutoProxy, CCmdTarget)

Cbbsc3mfcDlgAutoProxy::Cbbsc3mfcDlgAutoProxy()
{
	EnableAutomation();
	
	// To keep the application running as long as an automation 
	//	object is active, the constructor calls AfxOleLockApp.
	AfxOleLockApp();

	// Get access to the dialog through the application's
	//  main window pointer.  Set the proxy's internal pointer
	//  to point to the dialog, and set the dialog's back pointer to
	//  this proxy.
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(Cbbsc3mfcDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(Cbbsc3mfcDlg)))
		{
			m_pDialog = reinterpret_cast<Cbbsc3mfcDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

Cbbsc3mfcDlgAutoProxy::~Cbbsc3mfcDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void Cbbsc3mfcDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(Cbbsc3mfcDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(Cbbsc3mfcDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// Note: we add support for IID_Ibbsc3mfc to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .IDL file.

// {F81D591F-7AF6-4B0F-B9DC-BBCF734DDE3F}
static const IID IID_Ibbsc3mfc =
{ 0xF81D591F, 0x7AF6, 0x4B0F, { 0xB9, 0xDC, 0xBB, 0xCF, 0x73, 0x4D, 0xDE, 0x3F } };

BEGIN_INTERFACE_MAP(Cbbsc3mfcDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(Cbbsc3mfcDlgAutoProxy, IID_Ibbsc3mfc, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {02271C5C-0989-4496-B14A-EB2DBB7608F2}
IMPLEMENT_OLECREATE2(Cbbsc3mfcDlgAutoProxy, "bbsc3mfc.Application", 0x2271c5c, 0x989, 0x4496, 0xb1, 0x4a, 0xeb, 0x2d, 0xbb, 0x76, 0x8, 0xf2)


// Cbbsc3mfcDlgAutoProxy message handlers
