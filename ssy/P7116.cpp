#include<bits/stdc++.h>
using namespace std;
const int K=15,N=5e5+10,MOD=1e9+7;
int n,k;
int w[K],c[N],d[N];
int now[K];
int ans=0;
bool dfs(int step){
    if(step==k+1){
        int t[K];
        for(int i=1;i<=k;i++)
            t[i]=now[i];
        while(1){
            bool f=0;
            for(int i=1;i<=n;i++){
                t[c[i]]+=d[i];
                if(t[c[i]]<1||t[c[i]]>w[c[i]])
                    return 1;
                ans=(ans+1)%MOD;
            }
            for(int i=1;i<=k;i++)
                if(t[i]!=now[i])
                    f=1;
            if(!f)return 0;
        }
        return 1;
    }
    for(int i=1;i<=w[step];i++){
        now[step]=i;
        if(!dfs(step+1))
            return 0;
    }
    return 1;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)
        scanf("%d",&w[i]);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&c[i],&d[i]);
    printf("%d",dfs(1)?ans:-1);
    return 0;
}