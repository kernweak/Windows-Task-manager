// DiaChuangkou.cpp : 实现文件
//


#include "stdafx.h"
#include "MFC任务管理器.h"
#include "DiaChuangkou.h"
#include "afxdialogex.h"
#include<CommCtrl.h>

// CDiaChuangkou 对话框

int CDiaChuangkou::m = 0;

IMPLEMENT_DYNAMIC(CDiaChuangkou, CDialogEx)

CDiaChuangkou::CDiaChuangkou(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOGChuangkou, pParent)
{

}

CDiaChuangkou::~CDiaChuangkou()
{
}

void CDiaChuangkou::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
}

BOOL CALLBACK EnumWndProc(HWND hwnd, LPARAM lParam)
{
	// 窗口是否可视
	//if (::IsWindow(hwnd) && ::IsWindowVisible(hwnd) && ((GetWindowLong(hwnd, GWL_EXSTYLE)&WS_EX_TOOLWINDOW) != WS_EX_TOOLWINDOW) &&
	//	(GetWindowLong(hwnd, GWL_HWNDPARENT) == 0)) 
	{
		CDiaChuangkou *plist = (CDiaChuangkou*)lParam;
		if (!::IsWindowVisible(hwnd))
		{
			return TRUE;
		}

		// 窗口是否可激活
		//if (!::IsWindowEnabled(hwnd))
		//{
		//	return TRUE;
		//}
		// Do something
		char szTitle[255];
		::GetWindowTextW(hwnd, (LPWSTR)szTitle, sizeof(szTitle));
		CString str;//(szTitle);
		str.Format(L"%s", szTitle);
		plist->m_ListCtrl.InsertItem(CDiaChuangkou::m, str);
		TCHAR buf[128] = {};
		GetClassName(hwnd, buf, sizeof(buf));
		TCHAR buf1[128] = {};
		GetWindowModuleFileName(hwnd, buf1, sizeof(buf1));
		if (str.GetLength() > 0) {
			plist->m_ListCtrl.SetItemText(CDiaChuangkou::m, 1, buf);
			plist->m_ListCtrl.SetItemText(CDiaChuangkou::m, 2, buf1);
			CDiaChuangkou::m = CDiaChuangkou::m + 1;
		}
	}
	return TRUE;
}


BOOL CDiaChuangkou::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	DWORD dwOldStyle = m_ListCtrl.GetExtendedStyle();
	m_ListCtrl.SetExtendedStyle(
		dwOldStyle | LVS_EX_FULLROWSELECT |
		LVS_EX_GRIDLINES |
		LVS_EX_CHECKBOXES
	);
	CRect rc;
	m_ListCtrl.GetClientRect(rc);
	int nWidth = rc.Width();
	m_ListCtrl.InsertColumn(0, L"窗口名", 0, nWidth / 3);
	m_ListCtrl.InsertColumn(1, L"窗口所属的类的类名", 0, nWidth / 3);
	m_ListCtrl.InsertColumn(2, L"窗口句柄关联的模块的完整路径和文件名称", 0, nWidth / 3);

	//枚举窗口
	HWND hOldWnd = NULL;
	EnumWindows(EnumWndProc, (LPARAM)this);

	return TRUE;
}


BEGIN_MESSAGE_MAP(CDiaChuangkou, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDiaChuangkou::OnBnClickedOk)
END_MESSAGE_MAP()


// CDiaChuangkou 消息处理程序


void CDiaChuangkou::OnBnClickedOk()
{
	m_ListCtrl.DeleteAllItems();
	DWORD dwOldStyle = m_ListCtrl.GetExtendedStyle();
	m_ListCtrl.SetExtendedStyle(
		dwOldStyle | LVS_EX_FULLROWSELECT |
		LVS_EX_GRIDLINES |
		LVS_EX_CHECKBOXES
	);
	CRect rc;
	m_ListCtrl.GetClientRect(rc);
	int nWidth = rc.Width();
	m_ListCtrl.InsertColumn(0, L"窗口名", 0, nWidth / 3);
	m_ListCtrl.InsertColumn(1, L"窗口所属的类的类名", 0, nWidth / 3);
	m_ListCtrl.InsertColumn(2, L"窗口句柄关联的模块的完整路径和文件名称", 0, nWidth / 3);
	EnumWindows(EnumWndProc, (LPARAM)this);
	// TODO: 在此添加控件通知处理程序代码
}
