#pragma once
class CHAR
{
private:
	char Content;
	int length;
public:
	CHAR(char s = '\0');
	~CHAR(void);
	void setContent(char c);
	int getLength();
	char getContent();
};


