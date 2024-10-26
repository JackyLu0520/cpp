#include<bits/stdc++.h>
using namespace std;
constexpr int M=5010;
int m,n;
int d[2*M],cnt[2];
int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++){
        int op,l,r;scanf("%d%d%d",&op,&l,&r);
        if(op==1)   d[2*l]++,d[2*r-1]--;
        else    d[2*l-1]++,d[2*r]--;
    }
    for(int i=1;i<=2*m-1;i++)
        d[i]+=d[i-1];
    for(int i=1;i<=2*m-1;i++)
        cnt[i%2]+=(d[i]==0);
    printf("%d %d",cnt[1],cnt[0]);
    return 0;
}