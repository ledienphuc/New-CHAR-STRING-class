#pragma once
#include<iostream>
#include "CHAR.h"
#include <string>	
class STRING
{
	CHAR* content;
	int length;
public:
	STRING(char c= '\0');
	STRING(char *s);
	STRING(CHAR a);
	~STRING(void);
	char* getContent();
	int getLength();
	void setContent(CHAR *s);
	STRING* expand(CHAR c);
	STRING* expand(char c);
	STRING* expand(STRING const &s);
	STRING* expand(char* s);

	void remove(CHAR c){
	
	}
	void input();

};

