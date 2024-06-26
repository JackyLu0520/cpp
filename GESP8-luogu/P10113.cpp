#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,L=18,M=1e4+10;
int n,fa[N][L],q,depth[N],Max[N];
int f(int i,int j){
    if(fa[i][j]==-1)    fa[i][j]=f(f(i,j-1),j-1);
    return fa[i][j];
}
int d(int i){
    if(depth[i]==-1)    depth[i]=d(fa[i][0])+1;
    return depth[i];
}
int mx(int i){
    if(Max[i]==-1)   Max[i]=max(mx(fa[i][0]),i);
    return Max[i];
}
int lca(int u,int v){
    if(d(u)<d(v))   swap(u,v);
    int t=d(u)-d(v);
    for(int i=0;t;i++){
        if(t&1) u=f(u,i);
        t>>=1;
    }
    if(u==v)    return u;
    for(int i=L-1;i>=0;i--)
        if(f(u,i)!=f(v,i)){
            u=f(u,i);
            v=f(v,i);
        }
    return f(u,0);
}
int main(){
    memset(fa,-1,sizeof(fa));
    memset(depth,-1,sizeof(depth));
    memset(Max,-1,sizeof(depth));
    scanf("%d",&n);
    for(int i=1;i<n;i++)
        scanf("%d",&fa[i][0]);
    depth[0]=1;
    Max[0]=0;
    scanf("%d",&q);
    while(q--){
        int m,l;
        scanf("%d",&m);
        scanf("%d",&l);
        for(int i=2;i<=m;i++){
            int t;
            scanf("%d",&t);
            l=lca(l,t);
        }
        printf("%d\n",mx(l));
    }
    return 0;
}