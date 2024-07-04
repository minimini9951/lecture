#pragma once
#include <iostream>

class String
{
	char* str;

	void SetStr(const char* inStr);

public:

	//Constructors
	String(); //Default constructor
	String(const char* inStr);
	String(const String& otherS);

	//Destructor
	~String();

	//friend operator<<
	friend std::ostream& operator<< (std::ostream& os, const String& s);

	//Assignment Operator
	String& operator= (const String& otherString);

	//Any other fn we may need to make public
	//Lenght
	int Length() const;
	
	//Subscript operator []
	char& operator[](int index);

	//ToUpper
	void ToUpper();
	//ToLower
	void ToLower();
	//Input Operator >>	//CHECK
	friend std::istream& operator>> (std::istream& is, String& s);
	
	//Concatenate Strings
	String operator+(const String& rhs) const;
	String& operator+=(const String& rhs);

	String& operator<<(const String& rhs);

	//Compare Strings == , !=, < , > ,  <= , >= operator
	bool operator==(const String& otherS) const;
	bool operator!=(const String& otherS) const;

	bool operator<(const String& otherS) const;
	bool operator>(const String& otherS) const;

	bool operator<=(const String& otherS) const;
	bool operator>=(const String& otherS) const;

	explicit operator bool()const;

	//Remove All
	void RemoveAll();
	String& operator-();

	//Call ToUpper
	String& operator++();
	//Call ToLower
	String& operator--();
};