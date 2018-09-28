// ScoreDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MainFrm.h"
#include "教学事务管理.h"
#include "ScoreDlg.h"
#include "afxdialogex.h"
#include "教学事务管理Doc.h"
#include "教学事务管理View.h"


// ScoreDlg 对话框

IMPLEMENT_DYNAMIC(ScoreDlg, CDialogEx)

ScoreDlg::ScoreDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ScoreDlg::IDD, pParent)
{
	thiscourse="";
}

ScoreDlg::~ScoreDlg()
{
}

void ScoreDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_COURSE, CB_Course);
	DDX_Text(pDX,IDC_SCORE_STUDENT_NUMBER,studentnumber);
	DDX_Text(pDX,IDC_SCORE_SCORE,thisscore);
}


BEGIN_MESSAGE_MAP(ScoreDlg, CDialogEx)
	ON_BN_CLICKED(IDC_UPDATE, &ScoreDlg::OnBnClickedUpdate)
	ON_BN_CLICKED(IDOK, &ScoreDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// ScoreDlg 消息处理程序


void ScoreDlg::OnBnClickedUpdate()
{
	UpdateData(1);
	CMainFrame *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;
	C教学事务管理View *pView=(C教学事务管理View *)pMain->GetActiveView();
	C教学事务管理Doc *pDoc=(C教学事务管理Doc *)pView->GetDocument(); 
	POSITION pos;
	CStudent *pStu=NULL;
	CB_Course.ResetContent();
	for(int i=0;i<(pDoc->data_table).data_student.GetCount();i++)
	{
		pos=pDoc->data_table.data_student.FindIndex(i);
		pStu=&((pDoc->data_table).data_student.GetAt(pos));
		if(studentnumber==(pStu->student_number))
			break;
	}
	for(int i=0;i<5;i++)
	{
		if(pStu->course[i]!="")
			CB_Course.InsertString(i,pStu->course[i]);
	}
	UpdateData(0);

	// TODO: 在此添加控件通知处理程序代码
}


BOOL ScoreDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void ScoreDlg::OnBnClickedOk()
{
	CMainFrame *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;
	C教学事务管理View *pView=(C教学事务管理View *)pMain->GetActiveView();
	C教学事务管理Doc *pDoc=(C教学事务管理Doc *)pView->GetDocument(); 
	POSITION pos;
	CStudent *pStu=NULL;
	for(int i=0;i<(pDoc->data_table).data_student.GetCount();i++)
	{
		pos=(pDoc->data_table).data_student.FindIndex(i);
        pStu=&((pDoc->data_table).data_student.GetAt(pos));
		if(pStu->getstudent_number()==studentnumber)
			break;
	}
	CString CunText;
	CB_Course.GetLBText((CB_Course.GetCurSel()),CunText);
	int i=0;
	for(;i<5;i++)
	{
		if(CunText==pStu->course[i])
			break;
	}
	UpdateData(1);
	pStu->course_score[i]=_ttof(thisscore);
	pView->OnShow();
	CDialogEx::OnOK();
}
