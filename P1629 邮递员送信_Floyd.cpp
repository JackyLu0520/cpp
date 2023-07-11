#include<bits/stdc++.h>
using namespace std;
const int MAXN=1001,INF=0x3f3f3f3f;
int n,m,dis[MAXN][MAXN],ans=0;
void Floyd(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(dis[i][k]!=INF&&dis[k][j]!=INF&&dis[i][k]+dis[k][j]<dis[i][j])
					dis[i][j]=dis[i][k]+dis[k][j];
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)
				dis[i][j]=INF;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		dis[u][v]=w;
	}
	Floyd();
	for(int i=2;i<=n;i++)
		ans+=dis[1][i]+dis[i][1];
	cout<<ans;
	return 0;
}
