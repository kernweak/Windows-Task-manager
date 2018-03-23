// DiaJincheng.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC任务管理器.h"
#include "DiaJincheng.h"
#include "afxdialogex.h"
#include <TlHelp32.h>
#include "DiaMokuai.h"
#include "DiaDui.h"
#include "MFC任务管理器Dlg.h"

// CDiaJincheng 对话框

IMPLEMENT_DYNAMIC(CDiaJincheng, CDialogEx)

CDiaJincheng::CDiaJincheng(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOGJincheng, pParent)
{

}

CDiaJincheng::~CDiaJincheng()
{
}

BOOL CDiaJincheng::OnInitDialog()
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
	m_ListCtrl.InsertColumn(0, L"名称", 0, nWidth / 4);
	m_ListCtrl.InsertColumn(1, L"PID", 0, nWidth / 4);
	m_ListCtrl.InsertColumn(2, L"线程数", 0, nWidth / 4);
	m_ListCtrl.InsertColumn(3, L"父进程", 0, nWidth / 4);
	BianLi();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CDiaJincheng::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
}


BEGIN_MESSAGE_MAP(CDiaJincheng, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CDiaJincheng::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDOK, &CDiaJincheng::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CDiaJincheng::OnBnClickedmokuai)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CDiaJincheng::OnNMClickList1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDiaJincheng::OnBnClickeddui)
END_MESSAGE_MAP()


// CDiaJincheng 消息处理程序


void CDiaJincheng::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}

void CDiaJincheng::BianLi()
{
	HANDLE hTool32 = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if (INVALID_HANDLE_VALUE == hTool32)
	{
		printf("快照error!\n");
		return;
	}
	// 2. 开始遍历进程
	PROCESSENTRY32 ti = { sizeof(PROCESSENTRY32) };
	BOOL bRet = Process32First(hTool32, &ti);
	m_ListCtrl.InsertItem(0, ti.szExeFile);
	if (!bRet)
	{
		printf("Thread32First error!\n");
		return;
	}
	int i = 0;
	do
	{
		//if (ti.th32OwnerProcessID == dwPID)
		{
			m_ListCtrl.UpdateWindow();
			m_ListCtrl.InsertItem(i, ti.szExeFile);
			CString str;
			str.Format(_T("%ld"), ti.th32ProcessID);
			m_ListCtrl.SetItemText(i, 1, str);
			str.Format(_T("%ld"), ti.cntThreads);
			m_ListCtrl.SetItemText(i, 2, str);
			str.Format(_T("%ld"), ti.th32ParentProcessID);
			m_ListCtrl.SetItemText(i, 3, str);
			i++;
		}
	} while (Process32Next(hTool32, &ti));
	//MessageBox(0);
}



void CDiaJincheng::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	m_ListCtrl.DeleteAllItems();
	BianLi();
}


void CDiaJincheng::OnBnClickedmokuai()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDiaMokuai cm;
	//cm.pocessID = temp2;
	int n;
	n = _wtoi(temp2);
	GetParent()->GetParent()->SendMessage(WM_GETMOKUAI, n,3);//向模块dialog发消息
	//cm.DoModal();
}


void CDiaJincheng::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	int temp = pNMItemActivate->iItem;
	temp2 = m_ListCtrl.GetItemText(temp, 1);
	
}


void CDiaJincheng::OnBnClickeddui()
{
	// TODO: 在此添加控件通知处理程序代码
	int n;
	n = _wtoi(temp2);
	GetParent()->GetParent()->SendMessage(WM_GETDUI ,n, 3); 
}
