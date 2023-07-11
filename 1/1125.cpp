#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	string s;
	int c[26],i,j,minn,maxn;
	memset(c,0,sizeof(c));
	cin>>s;
	for(i=0;i<s.size();i++)
		c[s[i]-97]++;
	minn=100;
	maxn=0;
	for(i=0;i<26;i++)
	{
		if(c[i]>maxn)	maxn=c[i];
		if(c[i]<minn&&c[i]!=0)	minn=c[i];
	}
	if((maxn-minn)==0||(maxn-minn)==1)
	{
		cout<<"No Answer"<<endl;
		cout<<0;
		return 0;
	}
	for(i=2;i<(maxn-minn);i++)
		if((maxn-minn)%i==0)
		{
			cout<<"No Answer"<<endl;
			cout<<0;
			return 0; 
		} 
	cout<<"Lucky Word"<<endl;
	cout<<maxn-minn;
	return 0;
} 
