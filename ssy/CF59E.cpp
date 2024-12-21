#include<bits/stdc++.h>
using namespace std;
const int N=3010,M=20010;
int n,m,k;
int head[N],nxt[2*M],ver[2*M],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
unordered_set<long long>f;
long long Hash(int a,int b,int c){
    return 1ll*a*N*N+1ll*b*N+1ll*c;
}
queue<int>q;
int dis[2*M],pre[2*M];
int bfs(){
    memset(dis,0,sizeof(dis));
    memset(pre,0,sizeof(pre));
    q.push(tot-1);
    while(!q.empty()){
        int in_edge=q.front();
        q.pop();
        int p=ver[in_edge^1],u=ver[in_edge];
        if(u==n)    return in_edge;
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i];
            if(dis[i])  continue;
            if(f.count(Hash(p,u,v)))  continue;
            dis[i]=dis[in_edge]+1;
            pre[i]=in_edge;
            q.push(i);
        }
    }
    return 0;
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    add(0,1);add(1,0);//tot-1:0->1
    for(int i=1;i<=k;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        f.emplace(Hash(a,b,c));
    }
    int ed=bfs();
    if(ed==0)   printf("-1\n");
    else{
        printf("%d\n",dis[ed]);
        stack<int>stk;
        int cur=ed;
        while(cur!=tot-1){
            stk.emplace(cur);
            cur=pre[cur];
        }
        printf("1 ");
        while(!stk.empty()){
            printf("%d ",ver[stk.top()]);
            stk.pop();
        }
    }
    return 0;
}