#include<bits/stdc++.h>
using namespace std;
const int MAX=200001,inf=0x3f3f3f3f;
int n,ans=inf,in[MAX];
vector<int> adj[MAX];
void dfs(int u,int s,int len){
	in[u]--;
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(v==s){
			ans=min(ans,len);
			return;
		}
		dfs(v,s,len+1);
	}
}
int main(){
	cin>>n;
	for(int u=1;u<=n;u++){
		int v;
		cin>>v;
		adj[u].push_back(v);
		in[v]++;
	}
	queue<int> q;
	for(int i=1;i<=n;i++)
		if(!in[i])
			q.push(i);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<adj[u].size();i++){
			int v=adj[u][i];
			in[v]--;
			if(!in[v])	q.push(v);
		}
	}
	for(int i=1;i<=n;i++)
		if(in[i])
			dfs(i,i,1);
	cout<<ans;
	return 0;
}
