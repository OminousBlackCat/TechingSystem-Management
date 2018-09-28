#pragma once
#include "afxwin.h"


// ScoreDlg 对话框

class ScoreDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ScoreDlg)

public:
	ScoreDlg(CWnd* pParent = NULL);   // 标准构造函数
	CString studentnumber;
	CString thiscourse;
	CString thisscore;
	virtual ~ScoreDlg();

// 对话框数据
	enum { IDD = IDD_Score };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CComboBox CB_Course;
	afx_msg void OnBnClickedUpdate();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
