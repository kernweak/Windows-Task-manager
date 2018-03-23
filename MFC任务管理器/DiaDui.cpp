// DiaDui.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC任务管理器.h"
#include "DiaDui.h"
#include "afxdialogex.h"
#include <TlHelp32.h>
#include <wchar.h>

// CDiaDui 对话框

IMPLEMENT_DYNAMIC(CDiaDui, CDialogEx)

CDiaDui::CDiaDui(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOGDui, pParent)
{

}

CDiaDui::~CDiaDui()
{
}

void CDiaDui::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl2);
}

BOOL CDiaDui::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	DWORD dwOldStyle = m_ListCtrl2.GetExtendedStyle();
	m_ListCtrl2.SetExtendedStyle(
		dwOldStyle | LVS_EX_FULLROWSELECT |
		LVS_EX_GRIDLINES |
		LVS_EX_CHECKBOXES
	);
	CRect rc;
	m_ListCtrl2.GetClientRect(rc);
	int nWidth = rc.Width();
	m_ListCtrl2.InsertColumn(0, L"堆标识符", 0, nWidth / 2);
	m_ListCtrl2.InsertColumn(1, L"进程标识符id", 0, nWidth / 2);
	WORD n;
	n = _wtoi(pocessID);
	HANDLE hTool32 = CreateToolhelp32Snapshot(TH32CS_SNAPHEAPLIST, n);
	if (INVALID_HANDLE_VALUE == hTool32)
	{
		MessageBoxW(L"快照error!");
		//	printf("快照error!\n");
		return FALSE;
	}
	// 2. 开始遍历进程
	HEAPLIST32 ti = { sizeof(HEAPLIST32) };
	BOOL bRet = Heap32ListFirst(hTool32, &ti);
	CString str;
	str.Format(_T("%ld"), ti.th32HeapID);
	m_ListCtrl2.InsertItem(0, str);
	if (!bRet)
	{
		printf("Heap32ListFirst error!\n");
		return false;
	}
	int i = 0;
	do
	{
		//if (ti.th32OwnerProcessID == dwPID)
		{
			m_ListCtrl2.UpdateWindow();
			str.Format(_T("%ld"), ti.th32ProcessID);
			m_ListCtrl2.SetItemText(i, 1, str);
			i++;
		}
	} while (Heap32ListNext(hTool32, &ti));





	return true;
}


BEGIN_MESSAGE_MAP(CDiaDui, CDialogEx)
END_MESSAGE_MAP()


// CDiaDui 消息处理程序
