#include<iostream>
using namespace std;
int main()
{
	int i,j,num[26];
	char string[2000],ch;
	for(i=0;i<=26;i++)
	{
		num[i]=0;
	}
	gets(string);
	for(i=0;string[i]!='\0';i++)
	{
		num[string[i]-97]++;
    } 
    for(i=0;i<26;i++)
    {
    	ch=i+97;
		cout<<ch<<num[i]<<"  ";	
	}
    return 0;
}
