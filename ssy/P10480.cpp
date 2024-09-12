#include<bits/stdc++.h>
using namespace std;
const int N=3e4+10,M=3e4+10;
int n,m;
int head[N],nxt[M],ver[M],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
bitset<N>f[N];
int ind[N];
queue<int>q;
vector<int>a;
int main(){
    scanf("%d%d",&n,&m);
    while(m--){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);ind[v]++;
    }
    for(int i=1;i<=n;i++)
        if(!ind[i])
            q.push(i);
    while(!q.empty()){
        int u=q.front();q.pop();
        a.push_back(u);
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i];
            ind[v]--;
            if(!ind[v]) q.push(v);
        }
    }
    for(int i=a.size()-1;i>=0;i--){
        int u=a[i];
        f[u].set(u);
        for(int j=head[u];j;j=nxt[j])
            f[u]|=f[ver[j]];
    }
    for(int i=1;i<=n;i++)
        printf("%d\n",f[i].count());
    return 0;
}