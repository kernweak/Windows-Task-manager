#pragma once
#include"DiaChuangkou.h"
#include "DiaCpu.h"
#include "DiaDui.h"
#include "DiaJincheng.h"
#include "DiaMokuai.h"
#include "DiaXianCheng.h"
#include "DigInformation.h"

// CMyTableCtrl

class CMyTableCtrl : public CTabCtrl
{
	DECLARE_DYNAMIC(CMyTableCtrl)
	//CDialogEx* m_Dia[7];
	CDiaChuangkou CHuangkou;
	CDiaCpu Cpu;
	CDiaDui Dui;
	CDiaJincheng JinCheng;
	CDiaMokuai Mokuai;
	CDiaXianCheng XianCheng;
	CDigInformation Information;
public:
	CMyTableCtrl();
	virtual ~CMyTableCtrl();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTcnSelchange(NMHDR *pNMHDR, LRESULT *pResult);
	void hide();
};


