#include<bits/stdc++.h>
using namespace std;
constexpr int M=1e7+10,MOD=1e9+7;
int m,cnt[3],ans=0;
int b[2][M];
void dfs(int now){
    if(now>m){
        ans++;if(ans>=MOD)   ans-=MOD;
        /*for(int i=1;i<=m;i++)
            printf("%d ",b[0][i]);
        printf("\n");
        for(int i=1;i<=m;i++)
            printf("%d ",b[1][i]);
        printf("\n\n");*/
        return;
    }
    if(now==1){
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(i!=j){
                    cnt[i]--;cnt[j]--;
                    b[0][now]=i;b[1][now]=j;
                    if(cnt[i]>=0&&cnt[j]>=0)    dfs(now+1);
                    cnt[i]++;cnt[j]++;
                }
    }else{
        int i=3-b[0][now-1]-b[1][now-1],j=3-i-b[1][now-1];
        cnt[i]--;cnt[j]--;
        b[0][now]=i;b[1][now]=j;
        if(cnt[i]>=0&&cnt[j]>=0)    dfs(now+1);
        cnt[i]++;cnt[j]++;

        j=i;i=3-j-b[0][now-1];
        cnt[i]--;cnt[j]--;
        b[0][now]=i;b[1][now]=j;
        if(cnt[i]>=0&&cnt[j]>=0)    dfs(now+1);
        cnt[i]++;cnt[j]++;
    }
}
int main(){
    freopen("board.in","r",stdin);
    freopen("board.out","w",stdout);
    scanf("%d%d%d%d",&m,&cnt[0],&cnt[1],&cnt[2]);
    dfs(1);
    printf("%d",ans);
    return 0;
}