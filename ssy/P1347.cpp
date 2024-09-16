#include<bits/stdc++.h>
using namespace std;
const int N=30,M=610;
int n,m;
int head[N],nxt[M],ver[M],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int ind[N],outd[N];
string s;
int toposort(){//-1:no 0:unknown 1:yes
    int ind1[N]={0},dp[N]={0},ans=0;
    memcpy(ind1,ind,sizeof(ind1));
    s.clear();
    queue<int>q;
    for(int i=1;i<=n;i++)
        if(!ind1[i]){
            q.push(i);dp[i]=1;
        }
    while(!q.empty()){
        int u=q.front();q.pop();
        s+=char(u+'A'-1);
        for(int i=head[u];i;i=nxt[i]){
            int v=ver[i];
            ind1[v]--;
            dp[v]=max(dp[v],dp[u]+1);
            ans=max(ans,dp[v]);
            if(!ind1[v])    q.push(v);
        }
    }
    for(int i=1;i<=n;i++)
        if(ind1[i])
            return -1;
    return ans==n;
}
int res;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;
        do{u=getchar()-'A'+1;}while(u<1||u>26);
        do{v=getchar()-'A'+1;}while(v<1||v>26);
        add(u,v);ind[v]++;outd[u]++;
        res=toposort();
        if(res==1){
            printf("Sorted sequence determined after %d relations: %s.",i,s.c_str());
            return 0;
        }else if(res==-1){
            printf("Inconsistency found after %d relations.",i);
            return 0;
        }
    }
    printf("Sorted sequence cannot be determined.");
    return 0;
}