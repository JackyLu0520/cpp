#include<bits/stdc++.h>
using namespace std;
const int N=510;
int n=500,m,st=N;
int g[N][N];
int p[N];
int deg[N];
stack<int>s;
void dfs(int u){
    for(int v=1;v<=n;v++)
        if(g[u][v]){
            g[u][v]--;
            g[v][u]--;
            dfs(v);
        }
    s.push(u);
}
int main(){
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int u,v;scanf("%d%d",&u,&v);
        g[u][v]++;
        g[v][u]++;
        deg[u]++;deg[v]++;
        st=min(min(u,v),st);
    }
    for(int i=1;i<=n;i++)
        if(deg[i]%2){
            st=i;break;
        }
    dfs(st);
    while(!s.empty()){
        printf("%d\n",s.top());
        s.pop();
    }
    return 0;
}