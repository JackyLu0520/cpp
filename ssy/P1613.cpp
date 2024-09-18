#include<bits/stdc++.h>
using namespace std;
const int N=65,L=32;
int n,m;
int a[N][N],dp[N][N][L];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int u,v;scanf("%d%d",&u,&v);
        dp[u][v][0]=1;
    }
    for(int t=1;)
}