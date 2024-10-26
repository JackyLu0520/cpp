#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=2e5+10,K=2e5+10;
int n,m,k,q;
int head[N],nxt[M],ver[M],tot=1;
void add(int u,int v){
    ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;
}
int a[K];
bool b[N];
int main(){
    scanf("%*d%d%d%d%d",&n,&m,&k,&q);
    for(int i=1;i<=m;i++){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);
    }
    for(int i=1;i<=k;i++)
        scanf("%d",&a[i]);
    while(q--){
        int l,r,ans=n-1;scanf("%d%d",&l,&r);
        memset(b,0,sizeof(b));
        b[1]=1;
        for(int i=l;i<=r;i++){
            if(b[a[i]]) continue;
            for(int j=head[a[i]];j;j=nxt[j])
                if(b[ver[j]]){
                    ans--;
                    b[a[i]]=1;
                    break;
                }
        }
        printf("%d\n",ans);
    }
    return 0;
}