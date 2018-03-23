// MyTableCtrl.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC任务管理器.h"
#include "MyTableCtrl.h"
#include<Windows.h>

// CMyTableCtrl

IMPLEMENT_DYNAMIC(CMyTableCtrl, CTabCtrl)

CMyTableCtrl::CMyTableCtrl()
{

}

CMyTableCtrl::~CMyTableCtrl()
{
}


BEGIN_MESSAGE_MAP(CMyTableCtrl, CTabCtrl)
	ON_NOTIFY_REFLECT(TCN_SELCHANGE, &CMyTableCtrl::OnTcnSelchange)
END_MESSAGE_MAP()



// CMyTableCtrl 消息处理程序




void CMyTableCtrl::OnTcnSelchange(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	int nNum = GetCurSel();
	/*for (int i = 0;i < 7;i++) {
		if (i == nNum) {
			m_Dia[i]->ShowWindow(SW_SHOW);
		}
		else {
			m_Dia[i]->ShowWindow(SW_HIDE);
		}
	}*/
	hide();
	if (nNum == 0)
		CHuangkou.ShowWindow(SW_SHOW);
	if (nNum == 1)
		JinCheng.ShowWindow(SW_SHOW);
	if (nNum == 2)
		XianCheng.ShowWindow(SW_SHOW);
	if (nNum == 3)
		Mokuai.ShowWindow(SW_SHOW);
	if (nNum == 4)
		Dui.ShowWindow(SW_SHOW);
	if (nNum == 5)
		Cpu.ShowWindow(SW_SHOW);
	if (nNum == 6)
		Information.ShowWindow(SW_SHOW);

}

void CMyTableCtrl::hide()
{
	CHuangkou.  ShowWindow(SW_HIDE);
	Cpu.        ShowWindow(SW_HIDE);
	Dui.        ShowWindow(SW_HIDE);
	JinCheng.   ShowWindow(SW_HIDE);
	Mokuai.     ShowWindow(SW_HIDE);
	XianCheng.  ShowWindow(SW_HIDE);
	Information.ShowWindow(SW_HIDE);
}
