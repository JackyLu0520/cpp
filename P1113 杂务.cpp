#include<bits/stdc++.h>
using namespace std;
int n,ans,in[100010],len[100010],f[100010];
vector<int> adj[100010];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int v;
		cin>>v>>len[i];
		while(1){
			int u;
			cin>>u;
			if(u==0)	break;
			adj[u].push_back(v);
			in[v]++;
		}
	}
	queue<int> q;
	for(int i=1;i<=n;i++)
		if(in[i]==0){
			q.push(i);
			f[i]=len[i];
		}
	while(!q.empty()){
		int u=q.front();
		for(int i=0;i<adj[u].size();i++){
			int v=adj[u][i];
			f[v]=max(f[v],f[u]+len[v]);
			in[v]--;
			if(in[v]==0)	q.push(v);
		}
		q.pop();
		ans=max(ans,f[u]);
	}
	cout<<ans;
	return 0;
} 
