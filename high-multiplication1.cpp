#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int main(){
	string s1,s2;
	int a[2001]={0},b[2001]={0},c[4001]={0},x,i,j,as,bs,cs;
	cin>>s1>>s2;
	as=s1.size();bs=s2.size();
	for(i=0;i<as;i++)	a[as-i]=s1[i]-'0';
	for(i=0;i<bs;i++)	b[bs-i]=s2[i]-'0';
	for(i=1;i<=as;i++){
		for(j=1,x=0;j<=bs;j++){
			c[i+j-1]+=a[i]*b[j]+x;
			x=c[i+j-1]/10;
			c[i+j-1]%=10;
		}
		c[i+j-1]=x;
	}
	for(cs=as+bs;c[cs]==0&&cs>1;cs--)	;
	for(i=cs;i>0;i--)	cout<<c[i];
	return 0;
}
