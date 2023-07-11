#include<stdio.h>
using namespace std;
int main()
{
	int a[26]={0},i;
	char c,s[100000];
	gets(s);
	for(i=0;s[i]!='\0';i++)
		a[s[i]-'a']++;
	c='a';
	for(i=0;i<26;i++)
		if(a[c-'a']<a[i])
			c=i+'a';
	putchar(c);
	return 0;
}
