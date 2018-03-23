
// MFC任务管理器Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC任务管理器.h"
#include "MFC任务管理器Dlg.h"
#include "afxdialogex.h"
#include <windows.h>
#include <tchar.h>
#include"DiaChuangkou.h"
#include "DiaCpu.h"
#include "DiaDui.h"
#include "DiaJincheng.h"
#include "DiaMokuai.h"
#include "DiaXianCheng.h"
#include "DigInformation.h"

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
	DDX_Control(pDX, IDC_TAB1, m_MyTable);
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
	ON_MESSAGE(WM_GETMOKUAI, &CMFC任务管理器Dlg::OnGetmokuai)
	ON_MESSAGE(WM_GETDUI, &CMFC任务管理器Dlg::OnGetdui)
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

	m_MyTable.InsertItem(0, L"窗口");
	m_MyTable.InsertItem(1, L"进程");
	m_MyTable.InsertItem(2, L"线程");
	m_MyTable.InsertItem(3, L"模块");
	m_MyTable.InsertItem(4, L"堆");
	m_MyTable.InsertItem(5, L"CPU");
	m_MyTable.InsertItem(6, L"其他信息");
//m_MyTable.m_Dia[0] = new CDiaChuangkou();
//m_MyTable.m_Dia[1] = new CDiaJincheng();
//m_MyTable.m_Dia[2] = new CDiaXianCheng();
//m_MyTable.m_Dia[3] = new CDiaMokuai();
//m_MyTable.m_Dia[4] = new CDiaDui();
//m_MyTable.m_Dia[5] = new CDiaCpu();
//m_MyTable.m_Dia[6] = new CDigInformation();
//
//m_MyTable.m_Dia[0]->Create(IDD_DIALOGChuangkou, &m_MyTable);
//m_MyTable.m_Dia[1]->Create(IDD_DIALOGJincheng, &m_MyTable);
//m_MyTable.m_Dia[2]->Create(IDD_DIALOGXianCheng, &m_MyTable);
//m_MyTable.m_Dia[3]->Create(IDD_DIALOGMokuai, &m_MyTable);
//m_MyTable.m_Dia[4]->Create(IDD_DIALOGDui, &m_MyTable);
//m_MyTable.m_Dia[5]->Create(IDD_DIALOGCPU, &m_MyTable);
//m_MyTable.m_Dia[6]->Create(IDD_DIALOGInformation, &m_MyTable);
	m_MyTable.CHuangkou.Create(IDD_DIALOGChuangkou, &m_MyTable);
	m_MyTable.Cpu.Create(IDD_DIALOGCPU, &m_MyTable);
	m_MyTable.Dui.Create(IDD_DIALOGDui, &m_MyTable);
	m_MyTable.JinCheng.Create(IDD_DIALOGJincheng, &m_MyTable);
	m_MyTable.Mokuai.Create(IDD_DIALOGMokuai, &m_MyTable);
	m_MyTable.XianCheng.Create(IDD_DIALOGXianCheng, &m_MyTable);
	m_MyTable.Information.Create(IDD_DIALOGInformation, &m_MyTable);
	CRect rc;
	m_MyTable.GetClientRect(rc);
	rc.DeflateRect(2, 45, 2, 5);
		m_MyTable.CHuangkou.MoveWindow(rc);
		m_MyTable.Cpu.MoveWindow(rc);
		m_MyTable.Dui.MoveWindow(rc);
		m_MyTable.JinCheng.MoveWindow(rc);
		m_MyTable.Mokuai.MoveWindow(rc);
		m_MyTable.XianCheng.MoveWindow(rc);
		m_MyTable.Information.MoveWindow(rc);
		m_MyTable.hide();
		m_MyTable.CHuangkou.ShowWindow(SW_SHOW);
	//for (int i = 0;i < 7;i++) {
	//	m_MyTable.m_Dia[i]->MoveWindow(rc);
	//}
	//m_MyTable.m_Dia[0]->ShowWindow(SW_SHOW);
	//for (int i = 1;i < 7;i++) {
	//	m_MyTable.m_Dia[i]->ShowWindow(SW_HIDE);
	//}

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
	CString str;
	str.Format(_T("%d"), stcCreatTime.wYear);
	m_wenJianXinXi = wenJianMing;
	m_wenJianXinXi = wenJianMing+L" \r\n";
	m_wenJianXinXi = m_wenJianXinXi+L"创建日期：";
	m_wenJianXinXi = m_wenJianXinXi + str;
	m_wenJianXinXi = m_wenJianXinXi + L"Y/";
	str.Format(_T("%d"), stcCreatTime.wMonth);
	m_wenJianXinXi = m_wenJianXinXi + str;
	m_wenJianXinXi = m_wenJianXinXi + L"M/";
	str.Format(_T("%d"), stcCreatTime.wDay);
	m_wenJianXinXi = m_wenJianXinXi + str;
	m_wenJianXinXi = m_wenJianXinXi + L"D/";
	str.Format(_T("%d"), stcCreatTime.wHour);
	m_wenJianXinXi = m_wenJianXinXi + str;
	m_wenJianXinXi = m_wenJianXinXi + L"H:";
	str.Format(_T("%d"), stcCreatTime.wMinute);
	m_wenJianXinXi = m_wenJianXinXi + str;
	m_wenJianXinXi = m_wenJianXinXi + L"M:";
	str.Format(_T("%d"), stcCreatTime.wMinute);
	m_wenJianXinXi = m_wenJianXinXi + str;
	m_wenJianXinXi = m_wenJianXinXi + L"S\r\n";
	m_wenJianXinXi = m_wenJianXinXi + L"修改日期：";
	FileTimeToLocalFileTime(&wfad.ftLastWriteTime, &ftLocal);
	FileTimeToSystemTime(&ftLocal, &stcCreatTime);
	str.Format(_T("%d"), stcCreatTime.wYear);

	m_wenJianXinXi = m_wenJianXinXi + str;
	m_wenJianXinXi = m_wenJianXinXi + L"Y/";
	str.Format(_T("%d"), stcCreatTime.wMonth);
	m_wenJianXinXi = m_wenJianXinXi + str;
	m_wenJianXinXi = m_wenJianXinXi + L"M/";
	str.Format(_T("%d"), stcCreatTime.wDay);
	m_wenJianXinXi = m_wenJianXinXi + str;
	m_wenJianXinXi = m_wenJianXinXi + L"D/";
	str.Format(_T("%d"), stcCreatTime.wHour);
	m_wenJianXinXi = m_wenJianXinXi + str;
	m_wenJianXinXi = m_wenJianXinXi + L"H:";
	str.Format(_T("%d"), stcCreatTime.wMinute);
	m_wenJianXinXi = m_wenJianXinXi + str;
	m_wenJianXinXi = m_wenJianXinXi + L"M:";
	str.Format(_T("%d"), stcCreatTime.wMinute);
	m_wenJianXinXi = m_wenJianXinXi + str;
	m_wenJianXinXi = m_wenJianXinXi + L"S\r\n";

	DWORD64 qwFileSize = 0;
	qwFileSize = wfad.nFileSizeHigh;
	qwFileSize <<= sizeof(DWORD) * 8;
	qwFileSize += wfad.nFileSizeLow;
	
	DWORD64 G = 0, M = 0, K = 0, B = 0;
	B = qwFileSize % 1024;DWORD64 temp = 1;temp = qwFileSize;
	qwFileSize = qwFileSize - B;
	G = qwFileSize / 1024.0 / 1024 / 1024;
	//DWORD64 temp = 1024 * 1024 * 1024;
	//temp = temp * G;
	
	qwFileSize= qwFileSize - (1024*1024*1024*G)-B;
	
	M = qwFileSize / 1024.0 / 1024;

	qwFileSize = qwFileSize -( 1024 * 1024 * M);
	K = temp-(1024*1024*M)- (1024 * 1024 * 1024 * G)-B;
	K = K / 1024;
//	M= (qwFileSize - B-1024*K) % (1024 * 1024);
//	G = (qwFileSize - B - 1024 * K - 1024 * 1024 * M) / 1024;
	//qwFileSize = qwFileSize / 1024.0;//kb
	//qwFileSize = qwFileSize / 1024;//mB
	m_wenJianXinXi = m_wenJianXinXi + L"文件大小：";
	str.Format(_T("%dG%dM%dK%dB"), G,M,K,B);
	m_wenJianXinXi = m_wenJianXinXi + str;
	//m_wenJianXinXi = wenJianSum;
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


afx_msg LRESULT CMFC任务管理器Dlg::OnGetmokuai(WPARAM wParam, LPARAM lParam)
{
	CString pocessID;
	pocessID.Format(_T("%ld"), wParam);
	m_MyTable.Mokuai.pocessID = pocessID;
	m_MyTable.Mokuai.OnInitDialog();
	return 0;
}


afx_msg LRESULT CMFC任务管理器Dlg::OnGetdui(WPARAM wParam, LPARAM lParam)
{
	CString pocessID;
	pocessID.Format(_T("%ld"), wParam);
	m_MyTable.Dui.pocessID = pocessID;
	m_MyTable.Dui.OnInitDialog();
	return 0;
}
