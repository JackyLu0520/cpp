#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,m,a[N][N];
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
    int t;scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i][1]);
        for(int i=2;i<=n;i++)
            for(int j=1;j<=n;j++)
                a[i][j]=a[i-1][(j+n-1)%n];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                for(int k=1;k<=n;k++)
                    for(int l=1;l<=n;l++)
                        if(abs(k-i)+abs(l-j)<=m&&gcd(a[i][j],a[k][l]))
    }
}