#include<bits/stdc++.h>
using namespace std;
int n,m,f[1001],p[1001],g[1001];
int main(){
	int i,v;
	cin>>n>>m;
	for(i=1;i<=m;i++)	cin>>p[i]>>g[i];
	for(i=1;i<=m;i++)
		for(v=n;v>=1;v--)
			if(v>=p[i])
				f[v]=max(f[v],f[v-p[i]]+g[i]);
	cout<<f[n];
	return 0;
} 
