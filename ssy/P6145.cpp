#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,C=1e5+10;
int n,m,c;
int head[N],nxt[C],ver[C],e[C],tot=1;
void add(int u,int v,int w){
    ver[++tot]=v;e[tot]=w;nxt[tot]=head[u];head[u]=tot;
}
int ind[N]={0},s[N];
queue<int>q;
int main(){
    scanf("%d%d%d",&n,&m,&c);
    for(int i=1;i<=n;i++)
        scanf("%d",&s[i]);
    for(int i=1;i<=c;i++){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);ind[v]++;
    }
    for(int i=1;i<=n;i++)
        if(!ind[i])
            q.push(i);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i],w=e[i];
            s[v]=max(s[v],s[u]+w);
            ind[v]--;
            if(!ind[v])q.push(v);
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d\n",s[i]);
    return 0;
}