// DigInformation.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC任务管理器.h"
#include "DigInformation.h"
#include "afxdialogex.h"


// CDigInformation 对话框

IMPLEMENT_DYNAMIC(CDigInformation, CDialogEx)

CDigInformation::CDigInformation(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOGInformation, pParent)
{

}

CDigInformation::~CDigInformation()
{
}

void CDigInformation::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDigInformation, CDialogEx)
END_MESSAGE_MAP()


// CDigInformation 消息处理程序
