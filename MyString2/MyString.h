#pragma once

class MyString
{
private:
	char* str;

public:
	MyString();
	MyString(char * s);
	MyString(MyString& other);
	~MyString();
	MyString operator=(const MyString& other);
	MyString operator + (const MyString &other);
	bool operator == (const MyString &other);
	char* getStr() const;

};