#pragma once
#include "afxwin.h"


// ShowClassDlg 对话框

class ShowClassDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ShowClassDlg)

public:
	ShowClassDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ShowClassDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CComboBox Combox_Course;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
