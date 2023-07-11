#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
	string s1,s2;
	int a[101]={0},b[101]={0},c[102]={0},x,i,as,bs,cs;
	cin>>s1>>s2;
	as=s1.size();bs=s2.size();
	if(as<bs||as==bs&&s1<s2)	{s1.swap(s2);swap(as,bs);cout<<'-';}
	for(i=0;i<as;i++)	a[as-i]=s1[i]-'0';
	for(i=0;i<bs;i++)	b[bs-i]=s2[i]-'0';
	for(i=1,x=0;i<=as;i++){
		c[i]=a[i]-b[i]-x;
		x=c[i]<0;
		c[i]+=(c[i]<0)*10;
	}
	for(cs=as;c
	[cs]==0&&cs>1;cs--)	;
	for(i=cs;i>0;i--)	cout<<c[i];
	return 0;
}
