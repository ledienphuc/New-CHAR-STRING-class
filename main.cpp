#include"CHAR.h"
#include"STRING.h"
#include<iostream>
int main()
{
	CHAR c1, c2('c');
	STRING s1, s2("s2"), s3('a'), s4(c1);
	s1.expand(c2)->expand('a')->expand(s2)->expand("abc");//s1:"cas2abc"
	//s1.remove(c2).remove('d');//remove all character c2 in s1 ---s1:"as2ab"
	//s1.input();//nhap chuoi moi tu ban phim
	std::cout << s1.getContent() << std::endl;
	std::cout << s2.getContent() << std::endl;
	std::cout << c2.getContent() << std::endl;

	system("pause");
	return 0; 
}