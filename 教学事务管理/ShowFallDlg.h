#pragma once
#include "afxwin.h"


// ShowFallDlg 对话框

class ShowFallDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ShowFallDlg)

public:
	ShowFallDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ShowFallDlg();

// 对话框数据
	enum { IDD = IDD_SHOW_FALL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox Combox_Course;
	afx_msg void OnBnClickedOk();
};
