//=====================================================
// Jared Torp
// Friday March 1th
// Programming II Assignment #5
// Description: Mystring
//=====================================================

#include <iostream>
#include "MyString.h"


using namespace std;

MyString addfunc(MyString a, MyString b);
bool isEqual(MyString a, MyString b);

int main()
{
	//constructor testing
	MyString s1;
	MyString s2("billy");
	MyString s3(s2);
	char a[] = "hello";
	MyString s4(a);

	//passing a string literal and assigning it to s1
	s1 = "Joe"; 
	
	cout << "Before Assignment: " << endl;
	cout << s1 << " " << s2 << endl;

	//assigning s2 to s1
	s1 = s2;

	//couting the aftermath
	cout << "After assignment" << endl;
	cout << s1 << " " << s2 << endl;


	cout << "before assinging s1 and s2 to s3's value: " << endl;
	cout << s1 << " " << s2 << " " << s3 << endl;
	
	//assigning the values
	s1 = s2 = s3;

	//couting the values
	cout << s1 << " " << s2 << " " << s3 << endl;

	

	



	//compares s1 and s3 to the compare function, will return true
	if (isEqual(s1,s3))
	{
		cout << "These two mystrings are the same!" << endl;
	}
	else
	{
		cout << "These two MyStrings are not the same!" << endl;
	}

	
	//compares s1 and s4 to the compare function, will return false
	if (isEqual(s1, s4))
	{
		cout << "These two mystrings are the same!" << endl;
	}
	else
	{
		cout << "These two MyStrings are not the same!" << endl;
	}

	//setting s1 to my first name
	s1 = "Jared";
	//setting s2 to my last name
	s2 = "Torp";

	//call the function to add them together, returns a MyString, and puts it into s3
	s3 = addfunc(s1, s2);
	
	//cout the Cat String
	cout << s3 << endl;




	return 0;

}

//adding func
MyString addfunc(MyString a, MyString b)
{
	MyString temp;

	temp = a + b;

	return temp;

}


//bool true func
bool isEqual(MyString a, MyString b)
{
	bool Equal;
	
	if (a == b)
	{
		Equal = true;
	}
	else
	{
		Equal = false;
	}

	return Equal;
}