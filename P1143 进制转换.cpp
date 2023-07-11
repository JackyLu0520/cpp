#include<bits/stdc++.h>
using namespace std;
int n,m,a[40],num=0;
string s;
int main(){
	int i;
	cin>>n>>s>>m;
	a[0]=s.size();
	for(i=1;i<=a[0];i++)
		if(s[a[0]-i]>='A'&&s[a[0]-i]<='F')
			a[i]=s[a[0]-i]-'A'+10;
		else
			a[i]=s[a[0]-i]-'0';
	for(i=1;i<=a[0];i++)
		num+=a[i]*pow(n,i-1);
	for(i=1;num!=0;i++)
		a[i]=num%m,num/=m;
	if(i==1)	a[0]=1;
	else		a[0]=i-1;
	for(i=a[0];i>=1;i--)
		if(a[i]>=10)
			cout<<char(a[i]-10+'A');
		else
			cout<<a[i];
	return 0; 
}
