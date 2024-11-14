#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,L=18,A=10;
int n,m,q;
int head[N],nxt[2*N],ver[2*N],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
vector<int>kth[N][L];
int fa[N][L],depth[N];
vector<int> merge(vector<int>a,vector<int>b){
    vector<int>t;
    auto i=a.begin(),j=b.begin();
    while(i!=a.end()&&j!=b.end()){
        if(*i>*j){
            t.push_back(*j);
            j++;
        }else{
            t.push_back(*i);
            i++;
        }
        if(t.size()>=A) return t;
    }
    for(;i!=a.end()&&t.size()<A;i++)   t.push_back(*i);
    for(;j!=b.end()&&t.size()<A;j++)   t.push_back(*j);
    return t;
}
void dfs(int u,int p){
    fa[u][0]=p;depth[u]=depth[p]+1;
    for(int i=1;i<L;i++){
        fa[u][i]=fa[fa[u][i-1]][i-1];
        kth[u][i]=merge(kth[u][i-1],kth[fa[u][i-1]][i-1]);
    }
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i];
        if(v!=p)
            dfs(v,u);
    }
}
vector<int>query(int u,int v){
    vector<int>t;
    if(depth[u]<depth[v])   swap(u,v);
    int diff=depth[u]-depth[v];
    for(int i=0;diff;i++){
        if(diff&1){
            t=merge(t,kth[u][i]);
            u=fa[u][i];
        }
        diff>>=1;
    }
    if(u==v)    return merge(t,kth[u][0]);
    for(int i=L-1;i>=0;i--)
        if(fa[u][i]!=fa[v][i]){
            t=merge(merge(t,kth[u][i]),kth[v][i]);
            u=fa[u][i];
            v=fa[v][i];
        }
    return merge(merge(t,kth[u][1]),kth[v][0]);
}
int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    for(int i=1;i<=m;i++){
        int c;scanf("%d",&c);
        kth[c][0].push_back(i);
    }
    dfs(1,0);
    while(q--){
        int u,v,a;scanf("%d%d%d",&u,&v,&a);
        vector<int>t=query(u,v);
        printf("%d ",min(a,int(t.size())));
        for(int i=0;i<min(a,int(t.size()));i++)
            printf("%d ",t[i]);
        printf("\n");
    }
    return 0;
}