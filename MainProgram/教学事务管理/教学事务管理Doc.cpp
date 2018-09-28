
// 教学事务管理Doc.cpp : C教学事务管理Doc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "教学事务管理.h"
#endif

#include "MainFrm.h"
#include "教学事务管理Doc.h"
#include "教学事务管理View.h"
#include "Student.h"
#include "SignDlg.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// C教学事务管理Doc

IMPLEMENT_DYNCREATE(C教学事务管理Doc, CDocument)

BEGIN_MESSAGE_MAP(C教学事务管理Doc, CDocument)
	ON_COMMAND(ID_SIGN, &C教学事务管理Doc::OnSign)
END_MESSAGE_MAP()


// C教学事务管理Doc 构造/析构

C教学事务管理Doc::C教学事务管理Doc()
{
	// TODO: 在此添加一次性构造代码

}

C教学事务管理Doc::~C教学事务管理Doc()
{
}

BOOL C教学事务管理Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// C教学事务管理Doc 序列化

void C教学事务管理Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
	data_table.Serialize(ar);
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void C教学事务管理Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void C教学事务管理Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void C教学事务管理Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// C教学事务管理Doc 诊断

#ifdef _DEBUG
void C教学事务管理Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void C教学事务管理Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// C教学事务管理Doc 命令


void C教学事务管理Doc::OnSign()
{
	CStudent student;
	SignDlg dlg;
	if(dlg.DoModal()==IDOK)
	{
		student.setName(dlg.s_name);
		student.setclass_number(dlg.s_class);
		student.setstudent_number(dlg.s_student_number);
		data_table.data_number++;
		data_table.data_student.AddTail(student);
		
		for(int i=0;i<10;i++)
		{
			if(student.class_number!=""&&student.class_number==data_table.AllClass[i])
				break;
			if(student.class_number!=data_table.AllClass[i]&&data_table.AllClass[i]=="")
			{
				data_table.AllClass[i]=student.class_number;
				break;
			}
		}
		CMainFrame *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;
	    C教学事务管理View *pView=(C教学事务管理View *)pMain->GetActiveView();
		pView->OnShow();
		
	}
	// TODO: 在此添加命令处理程序代码
}
