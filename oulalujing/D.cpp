#include<bits/stdc++.h>
using namespace std;
int t,n,m;
struct E{
    int v;
    bool f;
    E(){}
    E(int V,bool F){v=V;f=F;}
}
bool cmp(E a,E b){
    a.v<b.v;
}
vector<E> adj[100010];
stack<int> s;
void dfs(int u){
    bool f=0;
    sort(adj[u].begin(),adj[u].end(),cmp);
    for(int i=0;i<adj[u].size();i++){
        if(adj[u][i].f){
            f=1;
            adj[u][i].f=0;
            dfs(adj[u][i].v);
        }
    }
    if(!f)  s.push(u);
}
int main(){;
    cin>>t;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(E(v,1));
        if(t==1)        adj[v].push_back(E(u,1));
    }
    
}
