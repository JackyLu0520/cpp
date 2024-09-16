#include<bits/stdc++.h>
using namespace std;
const int N=30,M=610;
int n,m;
int head[N],nxt[M],ver[M],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int ind[N],outd[N];
int toposort(){//-1:no 0:unknown 1:yes
    int ind1[N];
    memcpy(ind1,ind,sizeof(ind1));
    queue<int>q;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i];
            ind1[v]--;
            if(!ind1[v])    q.push(v);
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;
        getchar();u=getchar()-'A'+1;
        getchar();v=getchar()-'A'+1;
        add(u,v);ind[v]++;outd[u]++;
    }
}