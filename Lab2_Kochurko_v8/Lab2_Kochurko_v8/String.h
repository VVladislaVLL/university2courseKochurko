#pragma once
#include <iostream>
using namespace std;
class String
{
	friend ostream& operator<<(ostream& out, const String& strObj);
public:
	String();
	String(const char* strArray);
	String(const String& strObj);
	~String();
	void print(void);
	bool empty();
	int strlength();
	String& operator =(const String& str);
private:
	int length;
	char* str;
	void copy(const String& str);

};

