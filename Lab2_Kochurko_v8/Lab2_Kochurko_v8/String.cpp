#include <iostream>
#include "String.h"
using namespace std;

String::String()
{
	length = 0;
	str = new char[1];
	str[0] = '\0';
}

String::String(const char* strArray)
{
	length = strlen(strArray);
	str = new char[length + 1];
	for (int i = 0; i < length; i++) 
	{
		str[i] = strArray[i];
	}
	str[length] = '\0';
}

String::~String()
{
	delete [] str;
}

bool String::empty() 
{
	return (length > 1) ? false : true;
}

int String::strlength()
{
	return length;
}
void String::copy(const String& strObj)
{
	length = strObj.length;
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		str[i] = strObj.str[i];
	}
	str[length] = '\0';
}

String::String(const String& strObj)
{
	copy(strObj);
}

String& String::operator =(const String& strObj)
{
	copy(strObj);
	return *this;
}

void String::print(void)
{
	for (int i = 0; i < length; i++)
	{
		cout << str[i];
	}
}


ostream& operator<<(ostream& out, const String& strObj)
{
	out << strObj.str;
	return out;
}