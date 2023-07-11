#include<bits/stdc++.h>
using namespace std;
int fa[30001],t,dis[30001],size[30001];
int Find(int x){
	if(x!=fa[x]){
		int t=fa[x];
		fa[x]=Find(fa[x]);
		dis[x]+=dis[t];
	}
	return fa[x];
}
void Union(int x,int y){
	int xx=Find(x),yy=Find(y);
	dis[xx]+=size[yy];
	size[yy]+=size[xx];
	size[xx]=0;
	fa[xx]=yy;
}
int main(){
	cin>>t;
	for(int i=1;i<=30000;i++){
		fa[i]=i;
		size[i]=1;
	}
	while(t--){
		char cmd;
		int i,j;
		cin>>cmd>>i>>j;
		if(cmd=='M')	Union(i,j);
		else{
			if(Find(i)!=Find(j))	cout<<-1<<endl;
			else	cout<<abs(dis[i]-dis[j])-1<<endl;
		}
	}
	return 0;
} 
