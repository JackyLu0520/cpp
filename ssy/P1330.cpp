#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e5+10;
int n,m;
int head[N],nxt[2*M],ver[2*M],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int c[N],cnt[3];
void dfs(int u,int in_edge){
    c[u]=3-c[ver[in_edge^1]];
    cnt[c[u]]++;
    for(int i=head[u];i;i=nxt[i]){
        int v=ver[i];
        if((i^1)!=in_edge){
            if(c[v]&&c[v]+c[u]!=3){
                printf("Impossible");
                exit(0);
            }else if(!c[v])
                dfs(v,i);
        }
    }
}
int ans=0;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    c[0]=1;
    for(int i=1;i<=n;i++)
        if(!c[i]){
            dfs(i,0);
            ans+=min(cnt[1],cnt[2]);
            cnt[1]=0;cnt[2]=0;
        }
    printf("%d",ans);
    return 0;
}