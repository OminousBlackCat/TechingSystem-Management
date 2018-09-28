
// 教学事务管理View.h : C教学事务管理View 类的接口
//

#pragma once


class C教学事务管理View : public CListView
{
protected: // 仅从序列化创建
	C教学事务管理View();
	DECLARE_DYNCREATE(C教学事务管理View)

// 特性
public:
	C教学事务管理Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~C教学事务管理View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEdit();
	afx_msg void OnShow();
	afx_msg void OnChoose();
	afx_msg void OnScore();
	afx_msg void OnShowCourse();
	afx_msg void OnShowClass();
	void ShowClassTable(CString class_name);
	afx_msg void OnShowFall();
	void ShowFallTable(CString course_name);
	void ShowCourseTable(CString course_name);
	afx_msg void OnShowStudent();
	void ShowIndividualTable(CString stundent_number);
	afx_msg void OnShowaverage();
};

#ifndef _DEBUG  // 教学事务管理View.cpp 中的调试版本
inline C教学事务管理Doc* C教学事务管理View::GetDocument() const
   { return reinterpret_cast<C教学事务管理Doc*>(m_pDocument); }
#endif

