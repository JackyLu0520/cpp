#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int main(){
	string s1,s2;
	int a[101]={0},b[101]={0},c[102]={0},x,i,as,bs,cs;
	cin>>s1>>s2;
	as=s1.size();bs=s2.size();
	for(i=0;i<as;i++)	a[as-i]=s1[i]-'0';
	for(i=0;i<bs;i++)	b[bs-i]=s2[i]-'0';
	for(i=1,x=0;i<=max(as,bs);i++){
		c[i]=a[i]+b[i]+x;
		x=c[i]/10;
		c[i]%=10;
	}
	c[i]=x;
	if(c[i]==0)	cs=i-1;
	else		cs=i;
	for(i=cs;i>0;i--)	cout<<c[i];
	return 0;
}
