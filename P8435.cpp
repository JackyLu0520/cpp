#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5;
int n,m,t,dfn[MAXN+10],low[MAXN+10];
vector<int> adj[MAXN+10];
int s[MAXN+10],top;
vector<int> dcc[MAXN+10];
int dccid;
void dfs(int u,int root){
	dfn[u]=low[u]=++t;
    s[++top]=u;
	if(u==root&&adj[u].empty())	dcc[++dccid].push_back(u);
	for(int v:adj[u]){
		if(!dfn[v]){
			dfs(v,root);
			low[u]=min(low[u],low[v]);
			if(dfn[u]<=low[v]){
				dcc[++dccid].push_back(u);
				int t;
				while(top){
                    t=s[top--];
                    dcc[dccid].push_back(t);
                    if(t==v)    break;
                }
			}
		}else low[u]=min(low[u],dfn[v]);
	}
}
int main(){
    scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
        scanf("%d%d",&u,&v);
        if(u==v)    continue;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int u=1;u<=n;u++)
		if(!dfn[u]){
            memset(s,0,sizeof(s));
            top=0;
			dfs(u,u);
		}
    printf("%d\n",dccid);
	for(int i=1;i<=dccid;i++){
        printf("%ld ",dcc[i].size());
		for(auto j:dcc[i])	printf("%d ",j);
		printf("\n");
	}
	return 0;
}