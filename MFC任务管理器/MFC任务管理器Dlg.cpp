
// MFC任务管理器Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC任务管理器.h"
#include "MFC任务管理器Dlg.h"
#include "afxdialogex.h"
#include <windows.h>
#include <tchar.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define  WCHAR_TO_CHAR(lpW_Char, lpChar) \
    WideCharToMultiByte(CP_ACP, NULL, lpW_Char, -1, \
lpChar, _countof(lpChar), NULL, FALSE);

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFC任务管理器Dlg 对话框



CMFC任务管理器Dlg::CMFC任务管理器Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC_DIALOG, pParent)
	, m_foldload(_T(""))
	, m_wenJianXinXi(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC任务管理器Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCSHELLTREE1, m_SheelTree);
	DDX_Control(pDX, IDC_MFCSHELLLIST1, m_ShellList);
	DDX_Text(pDX, IDC_EDIT1, m_foldload);
	DDX_Text(pDX, IDC_EDIT2, m_wenJianXinXi);
}

BEGIN_MESSAGE_MAP(CMFC任务管理器Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_CLICK, IDC_MFCSHELLTREE1, &CMFC任务管理器Dlg::OnNMClickMfcshelltree1)
	ON_NOTIFY(NM_DBLCLK, IDC_MFCSHELLTREE1, &CMFC任务管理器Dlg::OnNMDblclkMfcshelltree1)
	ON_NOTIFY(TVN_SELCHANGING, IDC_MFCSHELLTREE1, &CMFC任务管理器Dlg::OnTvnSelchangingMfcshelltree1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC任务管理器Dlg::OnBnClickedClean)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC任务管理器Dlg::OnBnClickedHuoquWenjian)
	ON_NOTIFY(NM_CLICK, IDC_MFCSHELLLIST1, &CMFC任务管理器Dlg::OnNMClickMfcshelllist1)
END_MESSAGE_MAP()


// CMFC任务管理器Dlg 消息处理程序

BOOL CMFC任务管理器Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	UpdateData(true);

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	m_SheelTree.SetRelatedList(&m_ShellList);
	m_ShellList.EnableShellContextMenu(true);
	//CMenu m_Menu;
	m_Menu.LoadMenu(IDR_MENU1);
	SetMenu(&m_Menu);
	m_wenJianXinXi = L"此处显示文件信息";
	UpdateData(false);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFC任务管理器Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFC任务管理器Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFC任务管理器Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC任务管理器Dlg::OnNMClickMfcshelltree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	m_ShellList.GetCurrentFolder(m_foldload);
	UpdateData(false);
}


void CMFC任务管理器Dlg::OnNMDblclkMfcshelltree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	
	*pResult = 0;
	m_ShellList.GetCurrentFolder(m_foldload);
	UpdateData(false);
}


void CMFC任务管理器Dlg::OnTvnSelchangingMfcshelltree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	
	*pResult = 0;
	m_ShellList.GetCurrentFolder(m_foldload);
	UpdateData(false);
}


void CMFC任务管理器Dlg::OnBnClickedClean()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	TCHAR* p = (TCHAR*)m_foldload.GetBuffer();//L"D:\\project\\24_MFC_day007_3.2";// 
		
	EnumLoad(p);
	MessageBox(TEXT("清理结束"), TEXT("通知"), 0);
}

void CMFC任务管理器Dlg::EnumLoad(TCHAR * load)
{
	BOOL Flag = FALSE;
	TCHAR szSearchPath[MAX_PATH] = {};
	_stprintf_s(szSearchPath, MAX_PATH, L"%s\\*.*", load);
	WIN32_FIND_DATA wsd = {};
	HANDLE hFile = FindFirstFile(szSearchPath, &wsd);
	if (hFile == INVALID_HANDLE_VALUE) {
		return;
	}
	do {
		if (wsd.cFileName[0] == '.') {
			continue;
		}
		if (wsd.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY) {
			TCHAR oppo[MAX_PATH];
			_stprintf_s(oppo, MAX_PATH, L"%s\\%s", load, wsd.cFileName);
			if (_tcscmp(L"Debug", wsd.cFileName) == 0 || _tcscmp(L"Release", wsd.cFileName) == 0
				|| _tcscmp(L"ipch",wsd.cFileName) == 0) {
				//_stprintf_s(oppo, MAX_PATH, L"%s%s", oppo, "\0");
				deleteFolder(oppo);
				continue;
			}
			EnumLoad(oppo);
		}
		else {
			int Size = _tcslen(wsd.cFileName);
			if (NULL != StrStr(wsd.cFileName, L".db")) {
				TCHAR oppoStr[MAX_PATH];
				_stprintf_s(oppoStr, MAX_PATH, L"%s\\%s", load, wsd.cFileName);
				//deleteFolder(oppoStr);
				DeleteFile(oppoStr);
			}

		}
	} while (FindNextFile(hFile, &wsd));
}

void CMFC任务管理器Dlg::deleteFolder(TCHAR * load)
{
	

	/*char c[100] = {};
	CString temp1;
	temp1.Format(L"rd /s/q  %s", load);

	WCHAR_TO_CHAR(temp1.GetBuffer(), c);
	system(c);*/
	SHFILEOPSTRUCT FileOp = {};
	FileOp.fFlags = FOF_NOCONFIRMATION;
//	FileOp.hNameMappings = NULL;
//	FileOp.hwnd = NULL;
//	FileOp.lpszProgressTitle = NULL;
	CString temp = load;
	temp += '\0';
	FileOp.pFrom = temp;
//	FileOp.pTo = NULL;
	FileOp.wFunc = FO_DELETE;
	SHFileOperation(&FileOp);

}


void CMFC任务管理器Dlg::OnBnClickedHuoquWenjian()
{
	// TODO: 在此添加控件通知处理程序代码
	CString wenJianSum = m_foldload + L"\\"+wenJianMing;
	WIN32_FILE_ATTRIBUTE_DATA wfad;
	GetFileAttributesEx(wenJianSum, GetFileExInfoStandard, &wfad);
	FILETIME ftLocal;
	FileTimeToLocalFileTime(&wfad.ftCreationTime, &ftLocal);
	SYSTEMTIME stcCreatTime;
	FileTimeToSystemTime(&ftLocal, &stcCreatTime);
	
	
	m_wenJianXinXi = wenJianSum;
		//L"创建时间：";
	UpdateData(false);	
}


void CMFC任务管理器Dlg::OnNMClickMfcshelllist1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	m_ShellList.GetCurrentFolder(m_foldload);
	//m_ShellList.GetCurrentFolder(m_foldload);
	UpdateData(false);
	int temp = pNMItemActivate->iItem;
	wenJianMing = m_ShellList.GetItemText(temp, 0);
}
