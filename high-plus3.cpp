#include<bits/stdc++.h>
using namespace std;
string as,bs;
int a[510]={0},b[510]={0},c[510]={0};
int main(){
	int i;
	cin>>as>>bs;
	a[0]=as.size();	
	b[0]=bs.size();	
	for(i=1;i<=a[0];i++)	a[i]=as[a[0]-i]-'0';
	for(i=1;i<=b[0];i++)	b[i]=bs[b[0]-i]-'0';
	c[0]=max(a[0],b[0]);
	for(i=1;i<=c[0];i++)
		c[i]=a[i]+b[i];
	for(i=1;i<=c[0];i++){
		c[i+1]+=c[i]/10;
		c[i]%=10;
	}
	if(c[i]!=0)	c[0]+=1;
	for(i=c[0];i>=1;i--)
		cout<<c[i];
	return 0;
}
