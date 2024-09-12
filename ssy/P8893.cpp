#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int n,k,p,r;
int head[N],nxt[N*N],ver[N*N],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int ind[N]={0},s[N];
queue<int>q;
int d[N];
int main(){
    scanf("%d%d%d",&n,&k,&p);
    for(int i=1;i<=p;i++){
        int u;scanf("%d",&u);
        q.push(u);
    }
    scanf("%d",&r);
    for(int i=1;i<=r;i++){
        int v,s;
        scanf("%d%d",&v,&s);
        while(s--){
            int u;scanf("%d",&u);
            add(u,v);ind[v]++;
        }
    }
    while(!q.empty()){
        int u=q.front();q.pop();
        if(u==k){
            printf("%d",d[u]);
            return 0;
        }
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i];
            d[v]=d[u]+1;
            ind[v]--;
            if(!ind[v])q.push(v);
        }
    }
    printf("-1");
    return 0;
}