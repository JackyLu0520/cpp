#include<iostream>
using namespace std;
int main()
{
	string s1,s2,s3="";
	cin>>s1>>s2;
	if (s1.size()<s2.size())
	{ 
		swap(s1,s2);
		cout<<'-';
	}
	int l1=s1.size();
	int l2=s2.size();
	for (int i=1; i<=l1-l2; i++) s2="0"+s2; 
	int j=0;
	for (int i=l1-1; i>=0; i--)
	{
		int x1=s1[i]-'0';
		int x2=s2[i]-'0';
		int x3=x1-x2-j;
		j=(x3<0);
		x3+=10*(x3<0);
		char  ch=x3+'0';
		s3=ch+s3;
	}
	cout<<s3;
	return 0;
}
