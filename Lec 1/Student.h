#pragma once

class Student
{
	char* m_login;
	int m_age;
	int m_year;
	float m_gpa;

	void copyData(const Student& other);

public:
	Student(const Student& student);
	Student(const char* log, int age, int year, float gpa);
	
	~Student();

	Student& operator=(const Student& other);

	void setLogin(const char* loginName);
	void setAge(int age);
	void setYear(int year);
	void setGPA(float gpa);

	int getAge() const;
	int getYear() const;
	float getGPA() const;
	const char* getLogin() const;

	void Display() const;


		
};