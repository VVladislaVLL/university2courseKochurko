#include <iostream>
#include "String.h"
using namespace std;

String::String()
{
	str = new char[];
}

String::~String()
{
	delete [] str;
}

bool String::empty() 
{
	return (this->length == 0) ? true : false;
}
//
//char* String::get() 
//{
//	return this;
//}

String& String::operator=(const String& str)
{
    
    return *this;
}

char& String::operator[](int index) {
	return this->str[index];
}


//ostream& operator<<(ostream& out, const String& str)
//{
//	for (int i = 0; i < str.length; i++) {
//		out << str[i];
//	}
//	return out;
//}