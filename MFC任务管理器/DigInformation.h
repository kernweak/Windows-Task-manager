#pragma once


// CDigInformation 对话框

class CDigInformation : public CDialogEx
{
	DECLARE_DYNAMIC(CDigInformation)

public:
	CDigInformation(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDigInformation();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGInformation };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
