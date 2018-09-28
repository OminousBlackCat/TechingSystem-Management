

#include "StdAfx.h"
#include "CTable.h"

IMPLEMENT_SERIAL(Table,CObject,0)
Table::Table()
{
	data_number=0;
	for(int i=0;i<10;i++)
	{
		AllClass[i]="";
		AllCourse[i]="";
	}
}
void Table:: Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if(ar.IsStoring())
	{
		ar<<data_number;
		POSITION pos=data_student.GetHeadPosition();
		while(pos!=NULL)
		{
			(data_student.GetAt(pos)).Serialize(ar);
			data_student.GetNext(pos);
		}
		for(int i=0;i<10;i++)
		{
			ar<<AllClass[i]<<AllCourse[i];
		}
	}
	else
	{
		if(data_number>0)
		{
			for(int i=0;i<data_number;i++)
				data_student.RemoveTail();
		}
		ar>>data_number;
		for(int i=0;i<data_number;i++)
		{
			CStudent student;
			student.Serialize(ar);
			data_student.AddTail(student);
		}
		for(int i=0;i<10;i++)
		{
			ar>>AllClass[i]>>AllCourse[i];
		}
	}
}

Table::~Table()
{
}
