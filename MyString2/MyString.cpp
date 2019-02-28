// member function implementations go in this file
#include "MyString.h"
#include <string.h> //only use this for strlen and str functions
#include <iostream> //only for testing functions

using namespace std; //only for testing functions

//default constructor
MyString::MyString()
{
	str = nullptr;
}

//char* constructor
MyString::MyString(const char * s)
{
	cout << "The char* constructor was called: " << s << endl;

	str = new char[strlen(s) + 1];
	strcpy_s(str, strlen(s) + 1, s);

}

//copy constructor
MyString::MyString(MyString& other)
{
	cout << "The copy Constructor has been called!" << endl;
	str = new char[strlen(other.str) + 1];
	strcpy_s(str, strlen(other.str) + 1, other.str);
}


//
MyString::~MyString()
{
	cout << "The destructor was called!" << endl;
	delete[] str;
}


//
MyString MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		delete[]  str;
		str = new char[strlen(other.str) + 1];
		strcpy_s(str, strlen(other.str) + 1, str);
	}

	return *this;
}

//overloaded + operator
MyString MyString::operator + (const MyString &other)
{
	MyString tempName;

	int fullSize;
	int firstSize = strlen(str); //the first string s1
	int secondSize = strlen(other.str); //isnt this the size of the address??


	fullSize = firstSize + secondSize + 2; //add the names together, including 2 because we need to insert a space and nullbyte
	tempName = new char[fullSize]; //is this suppose to be a new char or a mystring?

	strcpy_s(tempName.str, fullSize, str); //
	strcat_s(tempName.str, fullSize, " "); //
	strcat_s(tempName.str, fullSize, other.str); //





	return tempName;
}


//overloaded == operator
bool MyString::operator == (const MyString &other)
{
	bool isEqual;

	if (strcmp(str, other.str) == 0)
	{
		isEqual = true;
	}
	else
	{
		isEqual = false;
	}

	return isEqual;
}




//a getter c_str() that returns the internal c strig pointer as a const ptr
char* MyString::getStr() const
{
	return str;

}


//overloaded cout operator

ostream &operator<<(ostream &strm, const MyString&obj)
{
	strm << obj.getStr();
	return strm;
}