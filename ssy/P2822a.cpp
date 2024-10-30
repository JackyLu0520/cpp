#include<bits/stdc++.h>
using namespace std;
const int N=2010;
int t,k;
int C[N][N],s[N][N];
int main(){
    scanf("%d%d",&t,&k);
    memset(C,-1,sizeof(C));
    for(int i=0;i<N;i++)
        C[i][i]=C[i][0]=1;
    for(int i=1;i<N;i++)
        for(int j=1;j<i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%k;
    for(int i=0;i<N;i++)
        s[i][0]=(!C[i][0]),s[0][i]=(!C[0][i]);
    for(int i=1;i<N;i++)
        for(int j=1;j<N;j++)
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+(!C[i][j]);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        printf("%d\n",s[n][m]);
    }
    return 0;
}