#include<bits/stdc++.h>
#define int long long
using namespace std;
int exgcd(int a,int b,int &x,int &y){
    if(b==0){x=1,y=0;return a;}
    int d=exgcd(b,a%b,x,y);
    int z=x;x=y;y=z-(a/b)*y;
    return d;
}
signed main(){
    int a,b,x,y;
    scanf("%lld%lld",&a,&b);
    int d=exgcd(a,b,x,y);
    printf("%lld",(x%b+b)%b);
    return 0;
}