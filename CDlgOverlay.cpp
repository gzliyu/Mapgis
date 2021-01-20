// CDlgOverlay.cpp: 实现文件
//

#include "pch.h"
#include "MapApp.h"
#include "CDlgOverlay.h"
#include "afxdialogex.h"

// CDlgOverlay 对话框

IMPLEMENT_DYNAMIC(CDlgOverlay, CDialogEx)

CDlgOverlay::CDlgOverlay(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_OVERLAY, pParent)
	, m_ClipKey(0)
	, m_SubKey(0)
	, red(0)
	, green(0)
	, blue(0)
{

}

CDlgOverlay::~CDlgOverlay()
{
}

void CDlgOverlay::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);


	DDX_Text(pDX, IDC_EDIT2, m_ClipKey);
	DDX_Text(pDX, IDC_EDIT1, m_SubKey);


	DDX_Text(pDX, IDC_REDEDIT, red);
	DDX_Text(pDX, IDC_GREENEDIT, green);
	DDX_Text(pDX, IDC_BLUEEDIT, blue);


}


BEGIN_MESSAGE_MAP(CDlgOverlay, CDialogEx)
	ON_COMMAND(ID_OVERLAY, &CDlgOverlay::OnOverlay)
	ON_BN_CLICKED(IDOK, &CDlgOverlay::OnBnClickedOk)
	ON_BN_CLICKED(IDC_INTERSECT, &CDlgOverlay::OnBnClicked)
	ON_BN_CLICKED(IDC_UNION, &CDlgOverlay::OnBnClicked)
	ON_BN_CLICKED(IDC_DIFF, &CDlgOverlay::OnBnClicked)
	ON_EN_CHANGE(IDC_EDIT2, &CDlgOverlay::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_REDEDIT, &CDlgOverlay::OnEnChangeEdit4)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgOverlay::OnColorBnClicked)
END_MESSAGE_MAP()


// CDlgOverlay 消息处理程序







void CDlgOverlay::OnOverlay()
{
	// TODO: 在此添加命令处理程序代码

}


void CDlgOverlay::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	bool unionState = ((CButton*)GetDlgItem(IDC_UNION))->GetCheck();//返回1表示选上，0表示没选上
	bool diffState = ((CButton*)GetDlgItem(IDC_DIFF))->GetCheck();//返回1表示选上，0表示没选上
	bool intersectState = ((CButton*)GetDlgItem(IDC_INTERSECT))->GetCheck();//返回1表示选上，0表示没选上
	bool xorState = ((CButton*)GetDlgItem(IDC_XOR))->GetCheck();//返回1表示选上，0表示没选上

	if (intersectState) {
		m_Select = 3;
	}
	else if (diffState) {
		m_Select = 1;
	}
	else if (unionState) {
		m_Select = 2;
	}
	else if (xorState) {
		m_Select = 4;
	}

	if (m_SubKey == -1 || m_ClipKey == -1)
	{
		AfxMessageBox(_T("关键字非法!"));
		return;
	}
	if (m_SubKey == m_ClipKey)
	{
		AfxMessageBox(_T("不能对同一个多边形叠置!"));
		return;
	}
	CDialogEx::OnOK();
}




void CDlgOverlay::OnBnClicked()
{
	// TODO: 在此添加控件通知处理程序代码




	
}



void CDlgOverlay::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CDlgOverlay::OnEnChangeEdit6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CDlgOverlay::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CDlgOverlay::OnColorBnClicked()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);

	printf("%d %d %d", red, green, blue);
}
