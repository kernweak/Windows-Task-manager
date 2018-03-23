// DiaDui.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC任务管理器.h"
#include "DiaDui.h"
#include "afxdialogex.h"


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
}


BEGIN_MESSAGE_MAP(CDiaDui, CDialogEx)
END_MESSAGE_MAP()


// CDiaDui 消息处理程序
