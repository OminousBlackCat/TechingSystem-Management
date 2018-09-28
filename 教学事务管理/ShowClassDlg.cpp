// ShowClassDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "教学事务管理.h"
#include "ShowClassDlg.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "教学事务管理Doc.h"
#include "教学事务管理View.h"
// ShowClassDlg 对话框

IMPLEMENT_DYNAMIC(ShowClassDlg, CDialogEx)

ShowClassDlg::ShowClassDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ShowClassDlg::IDD, pParent)
{

}

ShowClassDlg::~ShowClassDlg()
{
}

void ShowClassDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SHOW_CLASS, Combox_Course);
}


BEGIN_MESSAGE_MAP(ShowClassDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &ShowClassDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// ShowClassDlg 消息处理程序


BOOL ShowClassDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CMainFrame *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;
	C教学事务管理View *pView=(C教学事务管理View *)pMain->GetActiveView();
	C教学事务管理Doc *pDoc=(C教学事务管理Doc *)pView->GetDocument(); 
	CComboBox* pCom=((CComboBox*)GetDlgItem(IDC_SHOW_CLASS));
	for(int i=0;i<10;i++)
	{
		if(pDoc->data_table.AllClass[i]!="")
			pCom->AddString(pDoc->data_table.AllClass[i]);
	}
	UpdateData(0);
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void ShowClassDlg::OnBnClickedOk()
{

	CMainFrame *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;
	C教学事务管理View *pView=(C教学事务管理View *)pMain->GetActiveView();
	C教学事务管理Doc *pDoc=(C教学事务管理Doc *)pView->GetDocument(); 
	CString getCombox;
	int nIndex=Combox_Course.GetCurSel();
	Combox_Course.GetLBText(nIndex,getCombox);
	pView->ShowClassTable(getCombox);
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
