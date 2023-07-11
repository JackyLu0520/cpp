#include<bits/stdc++.h>
using namespace std;
int n,m,p,f[5010],mi,mj,pi,pj;
int Find(int x){
	if(f[x]!=x)	f[x]=Find(f[x]);
	return f[x];
}
void Union(int x,int y){
	f[Find(x)]=Find(y);
}
int main(){
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>mi>>mj;
		Union(mi,mj);
	}
	for(int i=1;i<=p;i++){
		cin>>pi>>pj;
		if(Find(pi)==Find(pj))
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
