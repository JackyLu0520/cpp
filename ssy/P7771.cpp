#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=2e5+10;
int n,m;
vector<int>g[N];
int dd[N];
vector<int>::iterator p[N];
stack<int>s;
void dfs(int u){
    for(vector<int>::iterator it=p[u];it!=g[u].end();it=p[u]){
        p[u]=it+1;
        dfs(*it);
    }
    s.push(u);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);dd[u]++;dd[v]--;
    }
    for(int u=1;u<=n;u++){
        sort(g[u].begin(),g[u].end());
        p[u]=g[u].begin();
    }
    bool f=0;
    int st=0;
    for(int i=1;i<=n;i++){
        if(dd[i]==0)    continue;
        if(dd[i]>1){f=1;break;}
        if(dd[i]==1){
            if(st){f=1;break;}
            st=i;
        }
    }
    if(f){
        printf("No");return 0;
    }
    if(st==0)    st=1;
    dfs(st);
    while(!s.empty())   printf("%d ",s.top()),s.pop();
    return 0;
}