// bbs-c3-mfcDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bbs-c3-mfc.h"
#include "bbs-c3-mfcDlg.h"
#include "DlgProxy.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Cbbsc3mfcDlg dialog

IMPLEMENT_DYNAMIC(Cbbsc3mfcDlg, CDialog);

Cbbsc3mfcDlg::Cbbsc3mfcDlg(CWnd* pParent /*=NULL*/)
	: CDialog(Cbbsc3mfcDlg::IDD, pParent)
//	, firstStart(_T("1203225001"))
//	, firstEnd(_T("1203225067"))
//	, secondStart(_T("1403225001"))
//	, secondEnd(_T("1403225067"))
//	, fileName(_T("c:\\Projects\\bbs\\1.csv"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

Cbbsc3mfcDlg::~Cbbsc3mfcDlg()
{
	// If there is an automation proxy for this dialog, set
	//  its back pointer to this dialog to NULL, so it knows
	//  the dialog has been deleted.
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void Cbbsc3mfcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_FIRST_START, firstStart);
	DDX_Text(pDX, IDC_FIRST_END, firstEnd);
	DDX_Text(pDX, IDC_SECOND_START, secondStart);
	DDX_Text(pDX, IDC_SECOND_END, secondEnd);
	DDX_Text(pDX, IDC_EDIT1, fileName);
	DDX_Control(pDX, IDC_FIRST_START, _firstStartCtrl);
	DDX_Control(pDX, IDC_START, _startBtn);
}

BEGIN_MESSAGE_MAP(Cbbsc3mfcDlg, CDialog)
	ON_WM_CLOSE()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BROWSE, &Cbbsc3mfcDlg::OnBnClickedBrowse)
	ON_EN_CHANGE(IDC_FIRST_START, &Cbbsc3mfcDlg::CheckField)
	ON_EN_CHANGE(IDC_FIRST_END, &Cbbsc3mfcDlg::CheckField)
	ON_EN_CHANGE(IDC_SECOND_START, &Cbbsc3mfcDlg::CheckField)
	ON_EN_CHANGE(IDC_SECOND_END, &Cbbsc3mfcDlg::CheckField)
	ON_EN_CHANGE(IDC_EDIT1, &Cbbsc3mfcDlg::CheckField)
	ON_BN_CLICKED(IDC_START, &Cbbsc3mfcDlg::OnBnClickedStart)
END_MESSAGE_MAP()


// Cbbsc3mfcDlg message handlers

BOOL Cbbsc3mfcDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	_firstStartCtrl.SetFocus();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Cbbsc3mfcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Cbbsc3mfcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// Automation servers should not exit when a user closes the UI if a controller still holds on to one of its objects.
// These message handlers make sure that if the proxy is still in use, then the UI is hidden but the dialog remains 
// around if it is dismissed.

void Cbbsc3mfcDlg::OnClose()
{
	if (CanExit())
		CDialog::OnClose();
}

void Cbbsc3mfcDlg::OnOK()
{
	if (CanExit())
		CDialog::OnOK();
}

void Cbbsc3mfcDlg::OnCancel()
{
	if (CanExit())
		CDialog::OnCancel();
}

BOOL Cbbsc3mfcDlg::CanExit()
{
	// If the proxy object is still around, then the automation controller is still holding on to this application.
	// Leave the dialog around, but hide its UI.
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}

void Cbbsc3mfcDlg::OnBnClickedBrowse()
{
		bool retVal = false;
		HWND hOwner = NULL;
		CString strTitle;

		std::string folderpath;
		BROWSEINFO bi;
		memset(&bi, 0, sizeof(bi));

		bi.ulFlags   = BIF_USENEWUI;
		bi.hwndOwner = hOwner;
		bi.lpszTitle = LPCTSTR(strTitle);

		// must call this if using BIF_USENEWUI
		::OleInitialize(NULL);

		// Show the dialog and get the itemIDList for the selected folder.

		LPITEMIDLIST pIDL = ::SHBrowseForFolder(&bi);

		if(pIDL != NULL)
		{
			// Create a buffer to store the path, then get the path.

			TCHAR buffer[_MAX_PATH] = {'\0'};
			if(::SHGetPathFromIDList(pIDL, buffer) != 0)
			{
				fileName = buffer;
				UpdateData(false);
				retVal = true;
			}

			// free the item id list
			CoTaskMemFree(pIDL);
		}

		::OleUninitialize();
//		return retVal;
	}

////
 /*
	OPENFILENAME ofn;
	CString strFilter;
	CString strFile;
	CString strTitle;

	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = m_hWnd;
	ofn.hInstance = ::AfxGetInstanceHandle();
	strFilter.LoadString(IDS_OPENFILEFILTER);
	strFilter.Replace((TCHAR)'|', (TCHAR)0); // в ресурсах фильтры для удобства разделены символом '|'
	ofn.lpstrFilter = LPCTSTR(strFilter);
	ofn.lpstrCustomFilter = NULL;
	ofn.nMaxCustFilter = 0;
	ofn.nFilterIndex = 0;
	ofn.lpstrFile = strFile.GetBuffer(MAX_PATH);
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	strTitle.LoadString(IDS_OPENFILETITLE);
	ofn.lpstrTitle = LPCTSTR(strTitle);
	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	ofn.nFileOffset = 0;
	ofn.nFileExtension = 0;
	ofn.lpstrDefExt = NULL;
	ofn.lCustData = 0;
	ofn.lpfnHook = NULL;
	ofn.lpTemplateName = NULL;

	#if(_WIN32_WINNT >= 0x0500)
		ofn.pvReserved = NULL;
		ofn.dwReserved = NULL;
		ofn.FlagsEx = 0;
	#endif // (_WIN32_WINNT >= 0x0500)

BOOL bLoad = ::GetOpenFileName(&ofn);
*/
//}

void Cbbsc3mfcDlg::CheckField()
{
	UpdateData(true);
	if( !firstStart.IsEmpty() 
	   && !firstEnd.IsEmpty() 
	   && !secondStart.IsEmpty() 
	   && !secondEnd.IsEmpty() 
	   && fileName.Find( L".csv" ) != -1
	   )
	{
		_startBtn.EnableWindow();
	}
	else
	{
		_startBtn.EnableWindow(FALSE);
	}

}

void Cbbsc3mfcDlg::OnBnClickedStart()
{
	TDATA data;
	memset(&data, 0, sizeof(TDATA));

	UpdateData(true);

	if(checkFile(fileName))
	{
		if( firstStart.GetLength() == 10
			&& firstEnd.GetLength() == 10
			&&  secondStart.GetLength() == 10
			&& secondEnd.GetLength() == 10
			)
		{
			data.firstStart = _ttol(firstStart);
			data.firstEnd = _ttol(firstEnd);
			data.secondStart = _ttol(secondStart);
			data.secondEnd = _ttol(secondEnd);

			if( data.secondEnd > data.secondStart && data.firstEnd > data.firstStart )
			{
				work.start( data, fileName);
				MessageBox( L"Работа окончена.", L"Поздравляю", MB_OK );
			}
			else
			{
				MessageBox( L"Конечные числа должны быть больше начальных.", L"Ошибка", MB_OK|MB_ICONERROR );
			}
		}
		else
		{
			MessageBox( L"Исходные числа должны быть десятизначными.", L"Ошибка", MB_OK|MB_ICONERROR );
		}
	}
	else
	{
		MessageBox( L"Файл уже существует, пожалуйста, укажите другое имя файла.", L"Ошибка", MB_OK|MB_ICONERROR );
	}
}

bool Cbbsc3mfcDlg::checkFile( const CString & fileName )
{
	HANDLE hFile;
	hFile = CreateFile( fileName, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL );
	if(hFile == INVALID_HANDLE_VALUE)
	{
		return true;
	}
	else
	{
		CloseHandle(hFile);
		return false;
	}
}
