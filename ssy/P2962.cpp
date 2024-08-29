#include<bits/stdc++.h>
using namespace std;
const int N=40,M=600;
int n,m,ans=0x3f3f3f3f;
bitset<N>a[N],l;
bool f=0;
void dfs(int x,int cnt){
    if(cnt>=ans)    return;
    if(x==0)ans=cnt;
    if(a[x][x]){
        bool t=a[x][n+1];
        for(int i=x+1;i<=n;i++)
            if(a[x][i])
                t^=l[i];
        dfs(x-1,cnt+t);
    }else{
        dfs(x-1,cnt);
        l.set(x);
        dfs(x-1,cnt+1);
        l.set(x,0);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    while(m--){
        int u,v;
        scanf("%d%d",&u,&v);
        a[u].set(v);
        a[v].set(u);
    }
    for(int i=1;i<=n;i++)
        a[i].set(i);
    for(int i=1;i<=n;i++)
        a[i].set(n+1);
    for(int i=1;i<=n;i++){
        int t=-1;
        for(int j=i;j<=n;j++)
            if(a[j][i]){
                t=j;break;
            }
        if(t==-1){f=1;continue;}
        swap(a[i],a[t]);
        for(int j=1;j<=n;j++)
            if(a[j][i]&&i!=j)
                a[j]^=a[i];
    }
    if(f){
        dfs(n,0);
        printf("%d",ans);
    }else{
        int cnt=0;
        for(int i=1;i<=n;i++)
            cnt+=a[i][n+1];
        printf("%d",cnt);
    }
    return 0;
}