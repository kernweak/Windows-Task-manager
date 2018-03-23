// DiaCpu.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC任务管理器.h"
#include "DiaCpu.h"
#include "afxdialogex.h"


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
}


BEGIN_MESSAGE_MAP(CDiaCpu, CDialogEx)
END_MESSAGE_MAP()


// CDiaCpu 消息处理程序
