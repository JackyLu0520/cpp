#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main(){
	string s1,s2;
	int a[101]={0},b,c[102]={0},x,i,as,cs;
	cin>>s1>>b;
	as=s1.size();
	for(i=0;i<as;i++)	a[as-i]=s1[i]-'0';
	for(i=as,x=0;i>=1;i--){
		x=x*10+a[i];
		c[i]=x/b;
		x=x%b;
	}
	for(cs=as;c[cs]==0&&cs>0;cs--)	;
	for(i=cs;i>0;i--)	cout<<c[i];
	cout<<' '<<x;
	return 0;
}
