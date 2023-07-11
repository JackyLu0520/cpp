#include<iostream>
#include<string>
using namespace std;
int main()
{ 
	string str1,str2;
	char s;
	int i;
	getline(cin,str1);
	str2="";
	for(i=0;i<str1.size();i++)
	{
		s=str1[i];
		if((s>='a'&&s<='z')||(s>='A'&&s<='Z'))
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
	return 0;
}
