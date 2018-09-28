// EditDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "教学事务管理.h"
#include "EditDlg.h"
#include "afxdialogex.h"


// EditDlg 对话框

IMPLEMENT_DYNAMIC(EditDlg, CDialogEx)

EditDlg::EditDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(EditDlg::IDD, pParent)
{

}

EditDlg::~EditDlg()
{
}

void EditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX,IDC_EDIT_STUDENT_NUMBER,studentnumber);
	DDX_Text(pDX,IDC_EDIT_NAME,Edit_Name);
	DDX_Text(pDX,IDC_EDIT_CLASS,Edit_class);
}


BEGIN_MESSAGE_MAP(EditDlg, CDialogEx)
END_MESSAGE_MAP()


// EditDlg 消息处理程序
