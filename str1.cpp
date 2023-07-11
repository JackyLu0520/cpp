#include<iostream>
using namespace std;
int main()
{
	int i,s,s1;
	char st[2000];
	s=s1=0;
	gets(st);
	for(i=0;st[i]!='\0';i++)
	{
		s++;
		if(st[i]=='.')
			s1++;
	}
	puts(st);
	cout<<s<<endl;
	cout<<s1;
	return 0;
}
