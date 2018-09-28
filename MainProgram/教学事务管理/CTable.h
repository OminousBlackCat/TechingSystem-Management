#include <afxtempl.h>
#include "Student.h"

class Table :public CObject
{
	DECLARE_SERIAL(Table)
public:
	Table();
	virtual ~Table();
	void Serialize(CArchive& ar);

	CList<CStudent,CStudent> data_student;
	int data_number;
	CString AllClass[10];
	CString AllCourse[10];
};