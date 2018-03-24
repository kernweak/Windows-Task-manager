// DiaCpu.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC任务管理器.h"
#include "DiaCpu.h"
#include "afxdialogex.h"
#include <Windows.h>
#include <WinBase.h>

// CDiaCpu 对话框

IMPLEMENT_DYNAMIC(CDiaCpu, CDialogEx)

CDiaCpu::CDiaCpu(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOGCPU, pParent)
{

}

CDiaCpu::~CDiaCpu()
{
}

void CDiaCpu::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_Memory);
	DDX_Control(pDX, IDC_LIST3, m_Cpu);
}


double FIETIME2Double(const _FILETIME& fileTime) {
	return double(fileTime.dwHighDateTime*4.294967296e9) + double(fileTime.dwLowDateTime);
}

int GetCpuUsage() {
	_FILETIME idleTime, kernelTime, userTime;
	GetSystemTimes(&idleTime, &kernelTime, &userTime);
	HANDLE hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	WaitForSingleObject(hEvent, 1000);
	_FILETIME newIdleTime, newKernelTime, newUserTime;
	GetSystemTimes(&newIdleTime, &newKernelTime, &newUserTime);
	double dOldIdleTime = FIETIME2Double(idleTime);
	double dNewIdleTime = FIETIME2Double(newIdleTime);
	double dOldKernelTime = FIETIME2Double(kernelTime);
	double dNewKernelTime = FIETIME2Double(newKernelTime);
	double dOldUserTime = FIETIME2Double(userTime);
	double dNewUserTime = FIETIME2Double(newUserTime);
	return int(100 - (dNewIdleTime - dOldIdleTime) / (dNewKernelTime - dOldKernelTime + dNewUserTime - dOldUserTime)*100.0);
}
DWORD WINAPI Proc(
	LPVOID lpParameter
) {
	CDiaCpu* cpu = (CDiaCpu*)lpParameter;
	MEMORYSTATUS memStatus;
	GlobalMemoryStatus(&memStatus);
	CString str;
	str.Format(_T("%d"), memStatus.dwMemoryLoad);
	cpu->m_Memory.SetItemText(0, 1, str);
	LONGLONG i = (memStatus.dwTotalPhys - memStatus.dwAvailPhys) / 1024 / 1024;

	str.Format(_T("%ldMB"), i);
	cpu->m_Memory.SetItemText(1, 1, str);

	str.Format(_T("%d"), GetCpuUsage());
	cpu->m_Cpu.SetItemText(0, 1, str);
	return 0;
}


BOOL CDiaCpu::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	MEMORYSTATUS memStatus;
	GlobalMemoryStatus(&memStatus);

	DWORD dwOldStyle = m_Memory.GetExtendedStyle();
	m_Memory.SetExtendedStyle(
		dwOldStyle | LVS_EX_FULLROWSELECT |
		LVS_EX_GRIDLINES 
	);
	CRect rc;
	m_Memory.GetClientRect(rc);
	int nWidth = rc.Width();
	m_Memory.InsertColumn(0, L"内存属性", 0, nWidth / 2);
	m_Memory.InsertColumn(1, L"数据", 0, nWidth / 2);
	m_Memory.InsertItem(0, L"当前内存占有率");
	m_Memory.InsertItem(1, L"已用物理内存大小");
	CString str;
	str.Format(_T("%d"), memStatus.dwMemoryLoad);
	m_Memory.SetItemText(0, 1, str);
	str.Format(_T("%d"), memStatus.dwTotalPhys-memStatus.dwAvailPhys);
	m_Memory.SetItemText(1, 1, str);



	DWORD dwOldStyle1 = m_Cpu.GetExtendedStyle();
	m_Cpu.SetExtendedStyle(
		dwOldStyle1 | LVS_EX_FULLROWSELECT |
		LVS_EX_GRIDLINES 
	);
	CRect rc1;
	m_Cpu.GetClientRect(rc1);
	int nWidth1 = rc1.Width();
	m_Cpu.InsertColumn(0, L"Cpu属性", 0, nWidth1 / 2);
	m_Cpu.InsertColumn(1, L"数据", 0, nWidth1 / 2);
	m_Cpu.InsertItem(0, L"CPU占有率");
	str.Format(_T("%d"), GetCpuUsage());
	m_Cpu.SetItemText(0, 1, str);
	//m_Memory.InsertItem(1, L"已用物理内存大小");



	SYSTEM_INFO i;
	GetSystemInfo(&i);
	//HWND hwndEdit = GetDlgItem(hwnd, IDC_EDITTIMER);

	
	SetTimer(WM_TIMER, 1000, NULL);

	return true;
}


BEGIN_MESSAGE_MAP(CDiaCpu, CDialogEx)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CDiaCpu 消息处理程序


void CDiaCpu::OnTimer(UINT_PTR nIDEvent)
{
	HANDLE hTread = INVALID_HANDLE_VALUE;
	hTread=CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Proc, this, NULL, NULL);
	WaitForSingleObject(hTread, 0);
	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	MEMORYSTATUS memStatus;
//GlobalMemoryStatus(&memStatus);
//CString str;
//str.Format(_T("%d"), memStatus.dwMemoryLoad);
//m_Memory.SetItemText(0, 1, str);
//LONGLONG i = (memStatus.dwTotalPhys - memStatus.dwAvailPhys) / 1024 / 1024;
//
//str.Format(_T("%ldMB"), i);
//m_Memory.SetItemText(1, 1, str);
//
//str.Format(_T("%d"), GetCpuUsage());
//m_Cpu.SetItemText(0, 1, str);

	
}

