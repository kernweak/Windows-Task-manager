#pragma once


// CDiaAbout 对话框

class CDiaAbout : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaAbout)

public:
	CDiaAbout(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDiaAbout();
	BOOL OnInitDialog();
	
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
