#include<bits/stdc++.h>
using namespace std;
const int ABC=1e6+10,M=1e6+10;
long long a,b,c,m,r[ABC],h[M],la[M],ra[M],lb[M],rb[M],lc[M],rc[M],diff[ABC],tmp[ABC];
int num(int i,int j,int k){
    return ((i-1)*b+(j-1))*c+(k-1)+1;
}
bool check(int x){
    memset(diff,0,sizeof(diff));
    memset(tmp,0,sizeof(diff));
    for(int i=1;i<=x;i++){
        diff[num(la[i],lb[i],lc[i])]+=h[i];
        diff[num(ra[i]+1,lb[i],lc[i])]-=h[i];
        diff[num(la[i],rb[i]+1,lc[i])]-=h[i];
        diff[num(la[i],lb[i],rc[i]+1)]-=h[i];
        diff[num(ra[i]+1,rb[i]+1,lc[i])]+=h[i];
        diff[num(ra[i]+1,lb[i],rc[i]+1)]+=h[i];
        diff[num(la[i],rb[i]+1,rc[i]+1)]+=h[i];
        diff[num(ra[i]+1,rb[i]+1,rc[i]+1)]-=h[i];
    }
    for(int i=1;i<=a;i++)
        for(int j=1;j<=b;j++)
            for(int k=1;k<=c;k++)
                tmp[num(i,j,k)]=tmp[num(i-1,j,k)]+tmp[num(i,j-1,k)]+tmp[num(i,j,k-1)]-
                                tmp[num(i-1,j-1,k)]-tmp[num(i,j-1,k-1)]-tmp[num(i-1,j,k-1)]+
                                tmp[num(i-1,j-1,k-1)]+diff[num(i,j,k)];
    for(int i=1;i<=a;i++)
        for(int j=1;j<=b;j++)
            for(int k=1;k<=c;k++)
                if(tmp[num(i,j,k)]>r[num(i,j,k)])
                    return 0;
    return 1;
}
int main(){
    scanf("%lld%lld%lld%lld",&a,&b,&c,&m);
    for(int i=1;i<=a*b*c;i++)
        scanf("%lld",&r[i]);
    for(int i=1;i<=m;i++)
        scanf("%lld%lld%lld%lld%lld%lld%lld",&la[i],&ra[i],&lb[i],&rb[i],&lc[i],&rc[i],&h[i]);
    long long l=1,r=m;
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid))
            l=mid+1;
        else
            r=mid;
    }
    printf("%lld",l);
    return 0;
}