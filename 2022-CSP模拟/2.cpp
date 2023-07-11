#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],g[100010],Min=2147483647;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		g[x]++;
		g[y]++;
	}
	if(m%2==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
		if(g[i]%2==1)
			Min=min(Min,a[i]);
	cout<<Min;
	return 0;
}