#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=2e6+10;
int n,m;
int head[N],nxt[2*M],ver[2*M],tot=1;
void add(int u,int v){
	ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int dfn[N],low[N],bridge[2*M],dfsid;
void tarjan(int u,int in_edge){
	dfn[u]=low[u]=++dfsid;
	for(int i=head[u];i;i=nxt[i]){
		int v=ver[i];
		if(!dfn[v]){
			tarjan(v,i);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u])
				bridge[i]=bridge[i^1]=1;
		}else if(i!=(in_edge^1))
			low[u]=min(low[u],dfn[v]);
	}
}
int c[N],dccid;
vector<int>cc[N];
void dfs(int u){
	c[u]=dccid;cc[dccid].push_back(u);
	for(int i=head[u];i;i=nxt[i]){
		int v=ver[i];
		if(c[v]||bridge[i])	continue;
		dfs(v);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i,0);
	for(int i=1;i<=n;i++)
		if(!c[i]){
			dccid++;
			dfs(i);
		}
	printf("%d\n",dccid);
	for(int i=1;i<=dccid;i++){
		printf("%d ",cc[i].size());
		for(int &j:cc[i])
			printf("%d ",j);
		printf("\n");
	}
	return 0;
}