#pragma once
#include "afx.h"
class CStudent :
	public CObject
{
public:
	CString Name;
	CString class_number;
	CString student_number;
	CString course[5];
	float course_score[5];



	DECLARE_SERIAL(CStudent);
	CStudent(void);
	CStudent(CStudent & student);
	CStudent& operator=(const CStudent& student);
	~CStudent(void);
	void setName(CString mingzi);
	void setclass_number(CString name_class);
	void setstudent_number(CString number_student);
	void setcourse(CString course_name);
	void setscore(double score_corse);
	CString getName();
	CString getclass_number();
	CString getstudent_number();
	bool ishave_student_number(CString number_student);
	void Serialize(CArchive& ar);
};

