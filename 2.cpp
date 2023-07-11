#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	char ch='A';
	putchar(ch);
	putchar('\x41');
	putchar(0x41);
	putchar(65);
	return 0;
}
