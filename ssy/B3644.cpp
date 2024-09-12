#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n;
int head[N],nxt[N*N],ver[N*N],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u],head[u]=tot;
}
int ind[N]={0};
queue<int>q;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        while(1){
            int t;scanf("%d",&t);
            if(t==0)    break;
            add(i,t);ind[t]++;
        }
    for(int i=1;i<=n;i++)
        if(!ind[i])
            q.push(i);
    while(!q.empty()){
        int u=q.front();q.pop();
        printf("%d ",u);
        for(int i=head[u];i;i=nxt[i]){
            ind[ver[i]]--;
            if(!ind[ver[i]])
                q.push(ver[i]);
        }
    }
    return 0;
}