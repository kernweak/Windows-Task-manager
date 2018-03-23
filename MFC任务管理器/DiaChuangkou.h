#pragma once
#include "afxcmn.h"


// CDiaChuangkou 对话框

class CDiaChuangkou : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaChuangkou)

public:
	CDiaChuangkou(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDiaChuangkou();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGChuangkou };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ListCtrl;
	static int m;
	afx_msg void OnBnClickedOk();
};
