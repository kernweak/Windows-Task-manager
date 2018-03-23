#pragma once
#include "afxcmn.h"


// CDiaMokuai 对话框

class CDiaMokuai : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaMokuai)

public:
	CDiaMokuai(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDiaMokuai();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGMokuai };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	CListCtrl m_ListCtrl2;
	CString pocessID;
	BOOL OnInitDialog();
	CListCtrl m_ListCtrl2;
};
