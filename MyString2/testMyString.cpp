//=====================================================
// Jared Torp
// Friday March 1th
// Programming II Assignment #5
// Description: Mystring
//=====================================================

#include <iostream>
#include "MyString.h"


using namespace std;

MyString addfunc(MyString a, MyString b); //prototype for the addition function
bool isEqual(MyString a, MyString b); //prototype for the boolean strcmp function
 

int main()
{
	//constructor testing
	MyString s1;
	MyString s2("billy");
	MyString s3(s2);
	char a[] = "hello";
	MyString s4(a);
	MyString s5;

	//couting an empty string
	cout << s1;
	
	cout << "Adding a MyString To an Empty MyString: " << endl;
	//calling the addfunc to test adding an empty MyString and a MyString
	s5 = addfunc(s1, s2);

	//cout-ing the result
	cout << s5 << endl;

	cout << "Testing a Mystring to equal itself and then cout-ing the result" << endl;
	s2 = s2;

	cout << s2 << endl;




	//passing a string literal and assigning it to s1
	s1 = "Joe"; 
	
	cout << "Before Assignment: " << endl;
	cout << s1 << " " << s2 << endl;

	//assigning s2 to s1
	s1 = s2;

	//couting the aftermath
	cout << "After assignment" << endl;
	cout << s1 << " " << s2 << endl;


	cout << "before assinging s1 and s2 to s4's value: " << endl;
	cout << s1 << " " << s2 << " " << s4 << endl;
	
	//assigning the values
	s1 = s2 = s4;


	//couting the values
	cout << s1 << " " << s2 << " " << s4 << endl;

	

	



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

//======================================================
// function name: addfunc
// parameters: 
//MyString a: we pass it the first MyString
//MyString b: we pass it the second MyString
// return type: MyString, we want a whole new MyString after adding a and b
//======================================================
MyString addfunc(MyString a, MyString b)
{
	MyString temp;

	temp = a + b;
	

	return temp;

}


//======================================================
// function name: isEqual
// parameters: 
//MyString a: we pass it the first MyString
//MyString b: we pass it the second MyString
// return type: bool, we want to knwo whether or not a and b are the same MyString
//======================================================
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

