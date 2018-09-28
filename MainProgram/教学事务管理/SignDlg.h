#pragma once


// SignDlg 对话框

class SignDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SignDlg)

public:
	SignDlg(CWnd* pParent = NULL);// 标准构造函数
	CString s_name;
	CString s_student_number;
	CString s_class;
	virtual ~SignDlg();

// 对话框数据
	enum { IDD = IDD_SIGN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
