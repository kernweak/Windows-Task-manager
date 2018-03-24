// DiaAbout.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC任务管理器.h"
#include "DiaAbout.h"
#include "afxdialogex.h"


// CDiaAbout 对话框

IMPLEMENT_DYNAMIC(CDiaAbout, CDialogEx)

CDiaAbout::CDiaAbout(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ABOUTBOX, pParent)
{

}

CDiaAbout::~CDiaAbout()
{
}

BOOL CDiaAbout::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	HMENU m_hMenu1 = NULL;
	::SetMenu(this->GetSafeHwnd(), m_hMenu1);
	return true;

}

void CDiaAbout::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDiaAbout, CDialogEx)
END_MESSAGE_MAP()


// CDiaAbout 消息处理程序
