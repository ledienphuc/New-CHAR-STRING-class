#include "CHAR.h"
#include <iostream>

CHAR::CHAR(char s)
{
	this->Content = s;
	this->length = 1;
	if (s == '\0')
		this->length = 0;
}


CHAR::~CHAR(void)
{
}
char CHAR::getContent(){
		return this->Content;
}
void CHAR::setContent(char c)
{
	this->Content = c;
	this->length = 1;
	if (c == '\0')
		this->length = 0;
}
int CHAR::getLength()
{
	return this->length;
}