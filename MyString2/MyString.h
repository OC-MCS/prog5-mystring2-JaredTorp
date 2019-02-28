#pragma once
#include <iostream>

using namespace std;

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

ostream& operator<<(ostream &strm, const MyString&obj);