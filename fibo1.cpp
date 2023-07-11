#include<bits/stdc++.h>
using namespace std;
string as,bs;
int a[1000010]={0},b[1000010]={0},c[1000010]={0},n;
int main(){
	int i,j;
	cin>>n;
	if(n==0){
		cout<<0;
		return 0;
	}
	a[0]=1;a[1]=1;
	b[0]=1;b[1]=1;
	for(j=2;j<=n;j++){
		c[0]=max(a[0],b[0]);
		for(i=1;i<=c[0];i++)
			c[i]=a[i]+b[i];
		for(i=1;i<=c[0];i++){
			c[i+1]+=c[i]/10;
			c[i]%=10;
		}
		if(c[i]!=0)	c[0]+=1;
		for(i=0;i<=b[0];i++)	a[i]=b[i];
		for(i=0;i<=c[0];i++)	b[i]=c[i];
	}
	for(i=b[0];i>=1;i--)	cout<<b[i];
	return 0;
}
