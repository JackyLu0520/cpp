#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10,L=11;
int n,m,a[N][L],lg[N];
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i][0]);
    for(int j=1;j<L;j++)
        for(int i=1;i<=n;i++)
            if(i+(1<<(j-1))<=n)
                a[i][j]=gcd(a[i][j-1],a[i+(1<<(j-1))][j-1]);
    lg[1]=0;
    for(int i=2;i<=n;i++)
        lg[i]=lg[i>>1]+1;
    while(m--){
        int l,r;
        scanf("%d%d",&l,&r);
        int t=lg[r-l+1];
        printf("%d\n",gcd(a[l][t],a[r-(1<<t)+1][t]));
    }
    return 0;
}