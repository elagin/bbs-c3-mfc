// bbs-c3-mfc.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Cbbsc3mfcApp:
// See bbs-c3-mfc.cpp for the implementation of this class
//

class Cbbsc3mfcApp : public CWinApp
{
public:
	Cbbsc3mfcApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Cbbsc3mfcApp theApp;