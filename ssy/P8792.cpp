#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,L=18;
int n,a[N][L],lg[N],cnt=0;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int query(int l,int r){
    int t=lg[r-l+1];
    return gcd(a[l][t],a[r-(1<<t)+1][t]);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i][0]);
        cnt+=(a[i][0]==1);
    }
    if(cnt){printf("%d",n-cnt);return 0;}
    for(int j=1;j<L;j++)
        for(int i=1;i<=n;i++)
            if(i+(1<<j)-1<=n)
                a[i][j]=gcd(a[i][j-1],a[i+(1<<(j-1))][j-1]);
    for(int i=2;i<=n;i++)
        lg[i]=lg[i>>1]+1;
    int i=1,j=1,ans=0x3f3f3f3f;
    while(j<=n){
        while(i<j&&query(i+1,j)==1) i++;
        if(query(i,j)==1)  ans=min(ans,j-i);
        j++;
    }
    if(ans==0x3f3f3f3f) printf("-1");
    else                printf("%d",n+ans-1);
    return 0;
}