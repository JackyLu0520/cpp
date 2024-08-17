#include<bits/stdc++.h>
using namespace std;
const int N=355,M=125,C=45;
int n,m,s[N],cnt[5];
int dp[C][C][C][C];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&s[i]);
    for(int i=1;i<=m;i++){
        int x;scanf("%d",&x);
        cnt[x]++;
    }
    dp[0][0][0][0]=s[1];
    for(int a=0;a<=cnt[1];a++)
        for(int b=0;b<=cnt[2];b++)
            for(int c=0;c<=cnt[3];c++)
                for(int d=0;d<=cnt[4];d++){
                    int id=1*a+2*b+3*c+4*d+1;
                    if(a!=0)    dp[a][b][c][d]=max(dp[a][b][c][d],dp[a-1][b][c][d]+s[id]);
                    if(b!=0)    dp[a][b][c][d]=max(dp[a][b][c][d],dp[a][b-1][c][d]+s[id]);
                    if(c!=0)    dp[a][b][c][d]=max(dp[a][b][c][d],dp[a][b][c-1][d]+s[id]);
                    if(d!=0)    dp[a][b][c][d]=max(dp[a][b][c][d],dp[a][b][c][d-1]+s[id]);
                }
    printf("%d",dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]]);
    return 0;
}