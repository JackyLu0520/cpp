#include<bits/stdc++.h>
using namespace std;
const int MAXN=201,INF=0x3f3f3f3f;
int n,m,dis[MAXN][MAXN],ans=0,q,k,t[MAXN];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(i!=j)
				dis[i][j]=INF;
	for(int i=0;i<n;i++)
		cin>>t[i];
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		dis[u][v]=min(dis[u][v],w);
		dis[v][u]=min(dis[v][u],w);
	}
	cin>>q;
	while(q--){
		int u,v,ti;
		cin>>u>>v>>ti;
		while(k<n&&t[k]<=ti){
			for(int i=0;i<n;i++)
				for(int j=0;j<n;i++)
					if(dis[i][k]!=INF&&dis[k][j]!=INF&&dis[i][k]+dis[k][j]<dis[i][j])
						dis[i][j]=dis[i][k]+dis[k][j];
			k++;
		}
		if(dis[u][v]==INF||t[u]>ti||t[v]>ti)	cout<<-1<<endl;
		else									cout<<dis[u][v]<<endl;
	}
	return 0;
}
