#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int sy,n;
struct seg{
    int l,r;
    inline bool operator<(const seg& a)const{
        return l<a.l;
    }
}ab,s[N];
int sum[N];
int main(){
    scanf("%d%d%d%d",&sy,&ab.l,&ab.r,&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&s[i].l,&s[i].r);
    sort(s+1,s+n+1);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+s[i].r-s[i].l;
    
}