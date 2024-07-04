#include "Student.h"
#include <iostream>

void Student::copyData(const Student& other)
{
	if (&other != this)
	{
		std::cout << "Called copyData for " << m_login << " with parameter: " << other.m_login << std::endl;

		setLogin(other.m_login);
		setAge(other.m_age);
		setYear(other.m_year);
		setGPA(other.m_gpa);
	}
}

Student::Student(const Student& student): m_login(nullptr), m_age(0), m_year(0), m_gpa(0.0f)
{
	std::cout << "Called Copy constructor to copy from" << student.m_login << std::endl;
	copyData(student);
}

Student::Student(const char* log, int age, int year, float gpa): m_login(nullptr), m_age(0), m_year(0), m_gpa(0)
{
	std::cout << "Called constructor of student " << log << std::endl;

	setLogin(log);
	setAge(age);
	setYear(year);
	setGPA(gpa);
}

Student::~Student()
{
	std::cout << "Called destructor of student " << m_login << std::endl;
	if (m_login != nullptr)
		delete[] m_login;
}

Student& Student::operator=(const Student& other)
{
	std::cout << "Called asignment operator (operator=) of student " << m_login << " to equal " << other.m_login << std::endl;
	if (&other != this)
		copyData(other);

	return *this;
}

void Student::setLogin(const char* loginName)
{
	//Allocate mem

	int size = 0;
	const char* p = loginName;

	while (*p != '\0')
	{
		size++;
		p++;
	}

	//inStr is size long (without the '\0' char)

	if (m_login != nullptr)
		delete[] m_login;

	//allocate memory for it
	m_login = new char[size + 1];

	//copy all values
	for (int i = 0; i < size; i++)
	{
		m_login[i] = loginName[i];
	}
	//Set null character
	m_login[size] = '\0';
}

void Student::setAge(int age)
{
	if (age < 18 || age > 99)
	{
		std::cout << "Invalid Age" << std::endl;
		m_age = -1;
	}
	else
	{
		m_age = age;
	}
}

void Student::setYear(int year)
{
	if (year < 0 || year > 3)
	{
		std::cout << "Invalid Year" << std::endl;
		m_year = -1;
	}
	else
	{
		m_year = year;
	}
}

void Student::setGPA(float gpa)
{
	if (gpa < 0.0f || gpa > 4.0f)
	{
		std::cout << "Invalid GPA" << std::endl;
		m_gpa = -1;
	}
	else
	{
		m_gpa = gpa;
	}
}

int Student::getAge() const
{
	return m_age;
}

int Student::getYear() const
{
	return m_year;
}

float Student::getGPA() const
{
	return m_gpa;
}

const char* Student::getLogin() const
{
	return m_login;
}

void Student::Display() const
{
	std::cout << m_login << std::endl;
	std::cout << " Age\t:" << m_age << std::endl;
	std::cout << " Year\t:" << m_year << std::endl;
	std::cout << " GPA\t:" << m_gpa << std::endl;

}
