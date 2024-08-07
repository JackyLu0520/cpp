#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
int num[N],nxt[N],pre[N],tot=0,head;
int pos[N],vis[N];
int main(){
    scanf("%d",&n);
    num[++tot]=1;nxt[tot]=0;pre[tot]=0;head=tot;pos[1]=tot;
    for(int i=2;i<=n;i++){
        int k,p;
        scanf("%d%d",&k,&p);
        num[++tot]=i;pos[i]=tot;
        if(p==0){
            nxt[tot]=pos[k];
            pre[tot]=pre[pos[k]];
            nxt[pre[pos[k]]]=tot;
            pre[pos[k]]=tot;
            if(head==pos[k]) head=tot;
        }else{
            pre[tot]=pos[k];
            nxt[tot]=nxt[pos[k]];
            pre[nxt[pos[k]]]=tot;
            nxt[pos[k]]=tot;
        }
    }
    scanf("%d",&m);
    while(m--){
        int x;
        scanf("%d",&x);
        if(!vis[x]){
            if(head==pos[x]) head=nxt[pos[x]];
            nxt[pre[pos[x]]]=nxt[pos[x]];
            pre[nxt[pos[x]]]=pre[pos[x]];
            vis[x]=1;
        }
    }
    for(int i=head;i;i=nxt[i])
        printf("%d ",num[i]);
    return 0;
}