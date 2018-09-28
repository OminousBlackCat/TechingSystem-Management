#pragma once


// EditDlg 对话框

class EditDlg : public CDialogEx
{
	DECLARE_DYNAMIC(EditDlg)

public:
	EditDlg(CWnd* pParent = NULL);// 标准构造函数
	CString studentnumber;
	CString Edit_Name;
	CString Edit_class;
	virtual ~EditDlg();

// 对话框数据
	enum { IDD = IDD_EDIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
