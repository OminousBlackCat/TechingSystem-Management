// ChooseDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "教学事务管理.h"
#include "ChooseDlg.h"
#include "afxdialogex.h"


// ChooseDlg 对话框

IMPLEMENT_DYNAMIC(ChooseDlg, CDialogEx)

ChooseDlg::ChooseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ChooseDlg::IDD, pParent)
{

}

ChooseDlg::~ChooseDlg()
{
}

void ChooseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX,IDC_CHOOSE_STUDENT_NUMBER,studentnumber);
	DDX_Text(pDX,IDC_CHOOSE_COURSE,coursenumber);
}


BEGIN_MESSAGE_MAP(ChooseDlg, CDialogEx)
END_MESSAGE_MAP()


// ChooseDlg 消息处理程序
