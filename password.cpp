#include<iostream>
#include<string>
using namespace std;
string str1,str2;
char s;
int i,z;
void a(void)
{
	getline(cin,str1);
	str2="";
	for(i=0;i<str1.size();i++)
	{
		s=str1[i];
		if((s>=97&&s<='z')||(s>='A'&&s<='Z'))
		{
			s--;
			if((s>'Z'&&s<'a')||s<'A')
			{
				s+=26;
			}
		}
		str2+=s;
	}
	cout<<str2;
}
void b(void)
{
	getline(cin,str1);
	str2="";
	for(i=0;i<str1.size();i++)
	{
		s=str1[i];
		if((s>=97&&s<='z')||(s>='A'&&s<='Z'))
		{
			s++;
			if((s>'Z'&&s<'a')||s>'z')
			{
				s-=26;
			}
		}
		str2+=s;
	}
	cout<<str2;
}
int main()
{
	cin>>z;
	switch(z)
	{
		case 1:b();break;
		case 2:a();break;
		default:break; 
	}
	return 0;	
}
