
// MFC任务管理器Dlg.h : 头文件
//

#pragma once
#include "afxshelltreectrl.h"
#include "afxshelllistctrl.h"
#include "MyTableCtrl.h"
#define WM_GETMOKUAI WM_USER +1 
#define WM_GETDUI WM_USER +2 

// CMFC任务管理器Dlg 对话框
class CMFC任务管理器Dlg : public CDialogEx
{
// 构造
public:
	CMFC任务管理器Dlg(CWnd* pParent = NULL);	// 标准构造函数
	CMenu m_Menu;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CMFCShellTreeCtrl m_SheelTree;
	CMFCShellListCtrl m_ShellList;
	CString m_foldload;
	afx_msg void OnNMClickMfcshelltree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMDblclkMfcshelltree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTvnSelchangingMfcshelltree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedClean();
	void EnumLoad(TCHAR* load);
	void deleteFolder(TCHAR* load);
	afx_msg void OnBnClickedHuoquWenjian();
	CString wenJianMing;//文件名
	afx_msg void OnNMClickMfcshelllist1(NMHDR *pNMHDR, LRESULT *pResult);
	CString m_wenJianXinXi;
	CMyTableCtrl m_MyTable;
protected:
	afx_msg LRESULT OnGetmokuai(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnGetdui(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void On32780();
};
