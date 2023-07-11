#include<iostream>
using namespace std;
int main()
{
	string s1,s2,s3="";
	int x1,x2,x3;
	char ch;
	cin>>s1>>s2;
	int l1=s1.size();
	int l2=s2.size();
	for (int i=1; i<=l1-l2; i++) s2="0"+s2; 
	int j=0;
	for (int i=l1-1; i>=0; i--)
	{
		x1=s1[i]-'0';
		x2=s2[i]-'0';
		x3=x1+x2+j;
		j=(x3>=10);
		x3-=10*(x3>=10);
		ch=x3+'0';
		s3=ch+s3;
	}
	cout<<s3;
	return 0;
}
