#include "STRING.h"

STRING::STRING(char c)
{
	this->content=new CHAR[2];
	this->content->setContent(c);
	this->content[1].setContent('\0');
	this->length=1;
	if (c == '\0')
		this->length = 0;
}
STRING::STRING(char *s)
{
	this->length=strlen(s);
	this->content=new CHAR[this->length+1];
	for(int i=0; i<length; i++)
	{
		this->content[i].setContent(s[i]);
	}
	this->content[length].setContent('\0');
}
STRING::STRING(CHAR a)
{
	this->content=new CHAR[2];
	if (a.getLength() != 0)
	{
		this->content->setContent(a.getContent());
		this->content[1].setContent('\0');
		this->length = 1;
	}
	else
	{
		this->content->setContent('\0');
		this->length = 0;
	}
}

STRING::~STRING(void)
{
	if (this->content != NULL){
		delete[] this->content;
		this->content = NULL;
	}
}

char* STRING::getContent() {
	char*s = new char[this->length];
	for (int i = 0; i < length; i++)
	{
		if (this->content[i].getContent() == '\0')
			break;
		s[i] = this->content[i].getContent();
	}
	s[length] = '\0';
	return s;
}

int STRING::getLength()
{
	return this->length;
}

STRING* STRING::expand(CHAR c)
{
	int LENGTH = this->length + 1;
	CHAR* s = new CHAR[LENGTH + 1];
	for (int i = 0; i < LENGTH + 1; i++){
		if (i == LENGTH)
		{
			s[i].setContent('\0');
		}
		else if (i == LENGTH - 1){
			s[i].setContent(c.getContent());
		}

		else
			s[i].setContent(this->content[i].getContent());
	}
	delete[] this->content;
	this->content = s;
	this->length = LENGTH;
	return this;
}

STRING* STRING::expand(char c)
{
	CHAR *s = new CHAR[this->length + 2];
	for (int i = 0; i < this->length + 2; i++){
		if (i == length + 1){
			s[i].setContent('\0');
		}
		else if (i == length){
			s[i].setContent(c);
		}
		else{
			s[i].setContent(this->content[i].getContent());
		}
	}
	delete[] this->content;
	this->content = s;
	this->length = length + 1;
	return this;
}

STRING* STRING::expand(STRING const &s)
{
	int LENGTH = this->length + s.length;
	CHAR *pStr = new CHAR[LENGTH + 1];
	for (int i = 0; i < LENGTH + 1; i++){
		if (i == LENGTH){
			pStr[i].setContent('\0');
		}
		else if (i >= s.length && i < LENGTH){
			pStr[i].setContent(s.content[i - this->length].getContent());
		}
		else{
			pStr[i].setContent(this->content[i].getContent());
		}
	}
	delete[] this->content;
	this->content = pStr;
	this->length = LENGTH;
	return this;
}

STRING* STRING::expand(char* s)
{
	int LENGTH = this->length + strlen(s);
	CHAR *pStr = new CHAR[LENGTH + 1];
	for (int i = 0; i < LENGTH + 1; i++){
		if (i == LENGTH){
			pStr[i].setContent('\0');
		}
		else if (i >= this->length && i < LENGTH){
			pStr[i].setContent(s[i - this->length]);
		}
		else{
			pStr[i].setContent(this->content[i].getContent());
		}
	}
	delete[] this->content;
	this->content = pStr;
	this->length = LENGTH;
	return this;
}

void STRING::input()
{
	char temp[1000];
	std::cin.getline(temp, 1000);
	this->length = strlen(temp);
	this->content = new CHAR[length + 1];
	for (int i = 0; i < length + 1; i++)
	{
		this->content[i].setContent(temp[i]);
	}
	this->content[length].setContent('\0');
}
