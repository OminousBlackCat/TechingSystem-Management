// SignDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "教学事务管理.h"
#include "SignDlg.h"
#include "afxdialogex.h"


// SignDlg 对话框

IMPLEMENT_DYNAMIC(SignDlg, CDialogEx)

SignDlg::SignDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(SignDlg::IDD, pParent)
{
	s_name="xxx";
	s_student_number="0000";
	s_class="00";
}

SignDlg::~SignDlg()
{
}

void SignDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX,IDC_SIGN_NAME,s_name);
	DDX_Text(pDX,IDC_SIGN_STUDENT_NUMBER,s_student_number);
	DDX_Text(pDX,IDC_SIGN_CLASS,s_class);
}


BEGIN_MESSAGE_MAP(SignDlg, CDialogEx)
END_MESSAGE_MAP()


// SignDlg 消息处理程序
