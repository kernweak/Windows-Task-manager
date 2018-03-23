#pragma once
#include "afxcmn.h"


// CDiaXianCheng 对话框

class CDiaXianCheng : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaXianCheng)

public:
	CDiaXianCheng(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDiaXianCheng();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGXianCheng };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ListCtrl;
	BOOL OnInitDialog();
	BOOL BianLi();
};
