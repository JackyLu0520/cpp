#include<bits/stdc++.h>
using namespace std;
const int N=110,INF=0x3f3f3f3f;
int n,a[2*N],s[2*N],dp1[2*N][2*N],dp2[2*N][2*N],ans1=INF,ans2=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++)    a[n+i]=a[i];
    for(int i=1;i<=2*n-1;i++)   s[i]=s[i-1]+a[i];
    for(int i=1;i<=2*n-1;i++)   dp1[i][i]=0,dp2[i][i]=0;
    for(int j=2;j<=2*n-1;j++)
        for(int i=j-1;i>=1;i--){
            dp1[i][j]=INF;dp2[i][j]=0;
            for(int k=i;k<j;k++){
                dp1[i][j]=min(dp1[i][j],dp1[i][k]+dp1[k+1][j]+s[j]-s[i-1]);
                dp2[i][j]=max(dp2[i][j],dp2[i][k]+dp2[k+1][j]+s[j]-s[i-1]);
            }
        }
    for(int i=1;i<=n;i++)    ans1=min(ans1,dp1[i][i+n-1]),ans2=max(ans2,dp2[i][i+n-1]);
    printf("%d\n%d",ans1,ans2);
    return 0;
}