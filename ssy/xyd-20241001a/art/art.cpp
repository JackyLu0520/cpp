#include<bits/stdc++.h>
using namespace std;
const int N=3010;
int n,m;
bool a[N][N];
int l[N][N],u[N][N],dp[N][N];
int ans=0;
int main(){
    //freopen("art.in","r",stdin);
    //freopen("art.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        char s[N];scanf("%s",s);
        for(int j=1;j<=m;j++)
            a[i][j]=(s[j]=='B');
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;){
            int k=j;
            while(k<m&&a[i][j]==a[i][j+1])   l[i][k]=j,k++;
            l[i][k]=j;j=k+1;
        }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            printf("%d ",l[i][j]);
        printf("\n");
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            printf("%d ",l[i][j]);
        printf("\n");
    }
    for(int j=1;j<=m;j++)
        for(int i=1;i<=n;){
            int k=i;
            while(k<=n&&a[i][j]==a[i][j-1])  u[k][j]=i,k++;
            i=k;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(i-u[i][j]>=dp[i-1][j-1]&&
                j-l[i][j]>=dp[i-1][j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=min(i-u[i][j],j-l[i][j])+1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            ans=max(ans,dp[i][j]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            printf("%d ",l[i][j]);
        printf("\n");
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            printf("%d ",l[i][j]);
        printf("\n");
    }
    printf("%d",ans);
    return 0;
}