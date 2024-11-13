#include<bits/stdc++.h>
using namespace std;
const int K=15,N=5e5+10,MOD=1e9+7;
int n,k;
int w[K],c[N],d[N];
int now[K];
int ans=0;
int cnt[10000010];
int num(int t[]){
    int ret=0;
    for(int i=k;i>=1;i--)
        ret=ret*w[i]+t[i];
    return ret;
}
bool dfs(int step){
    if(step==k+1){
        int t[K];
        for(int i=1;i<=k;i++)
            t[i]=now[i];
        if(cnt[num(t)]){
            ans=(ans+cnt[num(t)])%MOD;
            return 1;
        }
        int cnt1=0;
        while(1){
            bool f=0;
            for(int i=1;i<=n;i++){
                t[c[i]]+=d[i];
                cnt1=(cnt1+1)%MOD;
                if(t[c[i]]<1||t[c[i]]>w[c[i]]){
                    ans=(ans+cnt1)%MOD;
                    cnt[num(now)]=cnt1;
                    return 1;
                }
            }
            for(int i=1;i<=k;i++)
                if(t[i]!=now[i])
                    f=1;
            if(!f)return 0;
            if(cnt[num(t)]){
                ans=(ans+cnt[num(t)]+cnt1)%MOD;
                cnt[num(now)]=cnt[num(t)]+cnt1;
                return 1;
            }
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