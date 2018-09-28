#pragma once
#include "afxwin.h"



// ShowCourseDlg 对话框

class ShowCourseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ShowCourseDlg)

public:
	ShowCourseDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ShowCourseDlg();

// 对话框数据
	enum { IDD = IDD_SHOW_COURSE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CComboBox Combox_Course;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
