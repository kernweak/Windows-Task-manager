#pragma once
#include "afxcmn.h"


// CDiaDui 对话框

class CDiaDui : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaDui)

public:
	CDiaDui(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDiaDui();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGDui };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ListCtrl2;
	CString pocessID;
	BOOL OnInitDialog();
};
