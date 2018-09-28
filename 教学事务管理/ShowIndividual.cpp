// ShowIndividual.cpp : 实现文件
//

#include "stdafx.h"
#include "MainFrm.h"
#include "教学事务管理.h"
#include "afxdialogex.h"
#include "教学事务管理Doc.h"
#include "教学事务管理View.h"
#include "ShowIndividual.h"

// ShowIndividual 对话框

IMPLEMENT_DYNAMIC(ShowIndividual, CDialogEx)

ShowIndividual::ShowIndividual(CWnd* pParent /*=NULL*/)
	: CDialogEx(ShowIndividual::IDD, pParent)
{

}

ShowIndividual::~ShowIndividual()
{
}

void ShowIndividual::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STUDENT_NUMBER, CB_Student);
}


BEGIN_MESSAGE_MAP(ShowIndividual, CDialogEx)
	ON_BN_CLICKED(IDOK, &ShowIndividual::OnBnClickedOk)
END_MESSAGE_MAP()


// ShowIndividual 消息处理程序


BOOL ShowIndividual::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CMainFrame *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;
	C教学事务管理View *pView=(C教学事务管理View *)pMain->GetActiveView();
	C教学事务管理Doc *pDoc=(C教学事务管理Doc *)pView->GetDocument(); 
	
	POSITION pos;
	for(int i=0;i<pDoc->data_table.data_student.GetCount();i++)
	{
		pos=pDoc->data_table.data_student.FindIndex(i);
		CStudent* pStu=&(pDoc->data_table.data_student.GetAt(pos));
		CB_Student.AddString(pStu->student_number);
	}
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void ShowIndividual::OnBnClickedOk()
{
	CMainFrame *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;
	C教学事务管理View *pView=(C教学事务管理View *)pMain->GetActiveView();
	C教学事务管理Doc *pDoc=(C教学事务管理Doc *)pView->GetDocument();
	CString s_n;
	int n=CB_Student.GetCurSel();
	CB_Student.GetLBText(n,s_n);
	pView->ShowIndividualTable(s_n);
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
