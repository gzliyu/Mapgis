#pragma once


// CDlgOverlay 对话框

class CDlgOverlay : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgOverlay)

public:
	CDlgOverlay(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlgOverlay();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_OVERLAY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:

	void OnOverlay();
	long m_ClipKey;
	long m_SubKey;
	int m_Select;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClicked();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit6();
	afx_msg void OnEnChangeEdit4();


	int red;
	int green;
	int blue;
	afx_msg void OnColorBnClicked();


};
