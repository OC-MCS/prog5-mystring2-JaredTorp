// member function implementations go in this file
#include "MyString.h"
#include <string.h> //only use this for strlen and str functions
#include <iostream> //only for testing functions

using namespace std; //only for testing functions

//======================================================
// function name: MyString::MyString()
// parameters: none, its the default constructor
// return type: none, its the default constructor
//======================================================
MyString::MyString()
{
	str = nullptr; //sets the str in a MyString to nullptr
}
 
//======================================================
// function name: MyString::MyString(const char * s)
// parameters: const char * s, we pass it the pointer to a char to initilize the MyString
// return type: none, constructor
//======================================================
MyString::MyString(const char * s)
{
	cout << "The char* constructor was called: " << s << endl;

	str = new char[strlen(s) + 1];
	strcpy_s(str, strlen(s) + 1, s);

}

//======================================================
// function name: MyString::MyString
// parameters: 
// MyString& other: we pass the other MyString as a reference
// return type: none, its a constructor
//======================================================
MyString::MyString(MyString& other)
{

	if (other.str != nullptr)
	{
		cout << "The copy Constructor has been called!:  " << other.str << endl;
		str = new char[strlen(other.str) + 1];
		strcpy_s(str, strlen(other.str) + 1, other.str);
	}
	else
	{
		cout << "the copy constructor nullptr is called" << endl; //when couting a nullptr, the program ends
		str = nullptr;
	}

}


//======================================================
// function name: MyString::~MyString
// parameters: none, its a destructor
// return type: none, its a destructor
//======================================================
MyString::~MyString()
{
	cout << "The destructor was called!" << endl;
	delete[] str;
}


//======================================================
// function name: MyString MyString::MyString operator=
// parameters: 
//(const MyString& other), we pass the other string as a constant to keep consistency 
// and because we are not changing the other value
// return type: *this, points to the instance of the class making the function call
//======================================================
MyString MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		delete[]  str;
		str = new char[strlen(other.str) + 1];
		strcpy_s(str, strlen(other.str) + 1, other.str);
	}

	return *this;
}

//======================================================
// function name: MyString MyString::MyString operator+
// parameters: 
//(const MyString& other), we pass the other string as a constant to keep consistency 
// and because we are not changing the other value
// return type: MyString, we want to return the strcat MyString
//======================================================
MyString MyString::operator + (const MyString &other)
{
	MyString tempName; //set a temporary MyString

	
	if (str == nullptr && other.str != nullptr) //check to see if str has nothing in it
	{
		tempName.str = new char[strlen(other.str) + 1];
		strcpy_s(tempName.str, strlen(other.str) + 1, other.str);
		
	}
	else if (other.str == nullptr && str != nullptr) //check to see of other.str has nothing it it
	{
		tempName.str = new char[strlen(str) + 1];
		strcpy_s(tempName.str, strlen(str) + 1, str);
		
	}
	else if (str != nullptr && other.str != nullptr) //if both have something it str
	{
		

		int fullSize;
		int firstSize = strlen(str); //the length of str
		int secondSize = strlen(other.str); //the length other.str


		fullSize = firstSize + secondSize + 2; //add the names together, including 2 because we need to insert a space and nullbyte
		tempName.str = new char[fullSize]; //dynamically allocate memory for tempname.str

		strcpy_s(tempName.str, fullSize, str); //copy the first name
		strcat_s(tempName.str, fullSize, " "); //add a space
		strcat_s(tempName.str, fullSize, other.str); // add the other name
		
	}
	return tempName; //return the TempName, if both str and other.str have nothing, it will simply return TempName
}


//======================================================
// function name: bool MyString::MyString operator==
// parameters: 
//(const MyString& other), we pass the other string as a constant to keep consistency 
// and because we are not changing the other value
// return type: bool, we need to check if the values of str and other,str are the same
//======================================================
bool MyString::operator == (const MyString &other)
{
	bool isEqual;

	if (strcmp(str, other.str) == 0) //checks if they are the same
	{
		isEqual = true;
	}
	else
	{
		isEqual = false; //if not, returns false
	}

	return isEqual;
}




//======================================================
// function name: MyString::getstr() const
// parameters: none
// return type: str, we just want a function to return str
//======================================================
char* MyString::getStr() const
{
	return str;

}


//======================================================
// function name: ostream& operator<<
// parameters: 
//(ostream &strm, const MyString&obj), we pass the stream by refence
//also pass the MyString object by reference
// return type: return the strm, which is part of the ostream class
//======================================================
ostream& operator<<(ostream &strm, const MyString&obj)
{
	if (obj.getStr() == nullptr) //checking if the object is NULL
	{
		cout << "Hey, this is a nullptr" << endl;
	}
	else //if it is not NULL, then cout the str
	{
	strm << obj.getStr(); //calls to get the str
	}
	
	return strm;
}
