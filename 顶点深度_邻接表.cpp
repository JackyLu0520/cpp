#include<bits/stdc++.h>
using namespace std;
int fa[100010],n,m;
int depth(int m){
	return fa[m]==m?0:depth(fa[m])+1;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>fa[i];
	}
	cout<<depth(m);
	return 0;
}