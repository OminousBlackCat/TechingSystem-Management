#include "StdAfx.h"
#include "Student.h"

IMPLEMENT_SERIAL(CStudent,CObject,0)

CStudent::CStudent(void)
{
	Name="";
	class_number="";
	student_number="";
	for(int i=0;i<5;i++)
	{
		course[i]="";
		course_score[i]=-1;
	}
}
CStudent::CStudent(CStudent & student)
{
	Name=student.Name;
	class_number=student.class_number;
	student_number=student.student_number;
	for(int i=0;i<5;i++)
	{
		course[i]=student.course[i];
		course_score[i]=student.course_score[i];
	}
}
CStudent& CStudent::operator=( const CStudent& student)
{
	Name=student.Name;
	class_number=student.class_number;
	student_number=student.student_number;
	for(int i=0;i<5;i++)
	{
		course[i]=student.course[i];
		course_score[i]=student.course_score[i];
	}
	return *this;
}

void CStudent::setName(CString mingzi)
{
	Name=mingzi;
}
void CStudent::setclass_number(CString number_class)
{
	class_number=number_class;
}
void CStudent::setstudent_number(CString number_student)
{
	student_number=number_student;
}
bool CStudent::ishave_student_number(CString number_student)
{
	if(number_student==student_number)
		return 1;
	else
		return 0;
}
void CStudent::setcourse(CString course_name)
{
	for(int i=0;i<5;i++)
	{
		if(course_name!=course[i]&&course[i]=="")
		{
			course[i]=course_name;
			break;
		}
	}
}
void CStudent::setscore(double course_socre)
{

}

CString CStudent::getName()
{
	return Name;
}
CString CStudent::getclass_number()
{
	return class_number;
}
CString CStudent::getstudent_number()
{
	return student_number;
}
void CStudent::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if(ar.IsStoring())
	{
		ar<<Name<<class_number<<student_number;
		for(int i=0;i<5;i++)
			ar<<course[i];
		for(int i=0;i<5;i++)
			ar<<course_score[i];
	}
	else
	{
		ar>>Name>>class_number>>student_number;
		for(int i=0;i<5;i++)
			ar>>course[i];
		for(int i=0;i<5;i++)
			ar>>course_score[i];
	}
}



CStudent::~CStudent(void)
{
}
