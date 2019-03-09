#pragma once
#include <iostream>

using namespace std;
 
//prototypes for the functions

class MyString
{
private:
	char* str;
	 
public: 
	MyString();
	MyString(const char * s);
	MyString(MyString& other);
	~MyString();
	MyString operator=(const MyString& other);
	MyString operator + (const MyString &other);
	bool operator == (const MyString &other);
	char* getStr() const;

};

//the ostream prototype goes after the class, since it is not a part of the mystring class
ostream& operator<<(ostream &strm, const MyString&obj);