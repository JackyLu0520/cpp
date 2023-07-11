#include<bits/stdc++.h>
using namespace std;
int n,m,a[10010],vis[10010]={0},cnt=0;
int main(){
	int i=0,k=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	while(cnt<n-1){
		i++;
		if(i>n)	i=1;
		if(!vis[i])	k++;
		if(k==m){
			vis[i]=1;
			cnt++;
			k=0;
			m=a[i];
		}
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
			cout<<i;
	return 0;
}