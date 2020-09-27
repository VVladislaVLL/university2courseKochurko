#pragma once
#include <iostream>
using namespace std;
class String
{
	friend ostream& operator<<(ostream& out, const String& str);
public:
	String();
	~String();
	bool empty();
	char* get();
	char* set();

	char& operator[](int index);
private:
	int length;
	char* str;
};

