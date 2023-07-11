#include<bits/stdc++.h>
using namespace std;
const int MAXN=10001;
int a[MAXN],b[MAXN],g[MAXN],k[MAXN],n,x,y;
int main(){
	int i;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i]>>b[i]>>g[i]>>k[i];
	cin>>x>>y;
	for(i=n;i>=1;i--)
		if(a[i]<=x&&b[i]<=y&&a[i]+g[i]>=x&&b[i]+k[i]>=y)
			break;
	if(i==0)
		cout<<-1;
	else
		cout<<i;
	return 0;
} 
