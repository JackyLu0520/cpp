#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5;
int n,dfsid,dfn[MAXN+10],low[MAXN+10];
vector<int> adj[MAXN+10];
int s[MAXN+10],top;
vector<int> dcc[MAXN+10];
int dccid;
bool iscut[MAXN+10];
int x,y;
void tarjan(int u,int root){
	dfn[u]=low[u]=++dfsid;
    s[++top]=u;
	if(u==root&&adj[u].empty())	dcc[++dccid].push_back(u);
    int son=0;
	for(int v:adj[u]){
		if(!dfn[v]){
			tarjan(v,root);
			low[u]=min(low[u],low[v]);
            son++;
			if(dfn[u]<=low[v]){
                if(u!=root&&son>1)  iscut[u]=1;
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
    scanf("%d%d",&n);
	while(1){
		int u,v;
        scanf("%d%d",&u,&v);
        if(u==v)    continue;
        if(u==0&&v==0)  break;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
    scanf("%d%d",&x,&y);
	for(int u=1;u<=n;u++)
		if(!dfn[u])
			tarjan(u,u);
    //缩点[unfinished]
	return 0;
}