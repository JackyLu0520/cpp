#include<bits/stdc++.h>
using namespace std;
const int N=1010,M=1010,MOD=1e9+7;
int C[N][N];//C_n^m
int main(){
    for(int i=0;i<N;i++)
        C[i][0]=1;
    for(int i=1;i<N;i++)
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
    int t;
    scanf("%d",&t);
    while(t--){
        int n=0,m,a[M],ans=1;
        scanf("%*d%d",&m);
        for(int i=0;i<m;i++){
            scanf("%d",&a[i]);
            n+=a[i];
        }
        for(int i=0;i<m;i++){
            ans=(1LL*ans*C[n][a[i]])%MOD;
            n-=a[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}