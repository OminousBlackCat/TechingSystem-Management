#pragma once


// ChooseDlg 对话框

class ChooseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ChooseDlg)

public:
	ChooseDlg(CWnd* pParent = NULL);   // 标准构造函数
	CString studentnumber;
	CString coursenumber;
	virtual ~ChooseDlg();

// 对话框数据
	enum { IDD = IDD_CHOOSE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
