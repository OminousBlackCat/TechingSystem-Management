#pragma once
#include "afxwin.h"


// ShowIndividual 对话框

class ShowIndividual : public CDialogEx
{
	DECLARE_DYNAMIC(ShowIndividual)

public:
	ShowIndividual(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ShowIndividual();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox CB_Student;
	afx_msg void OnBnClickedOk();
};
