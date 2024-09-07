#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,x,ans=0;
int main(){
    scanf("%lld%lld",&a,&b);
    x=a*a-4*b;
    if(!x){printf("inf");return 0;}
    for(ll i=(a+1)%2+1;i*i<=(x>0?x:-x);i+=2){
        if(x%i)  continue;
        ll u=i,v=x/i;
        if(x<0) u=-u,v=-v;
        if((v-u)%4) continue;
        if(v-(v-u)/2<a) break;
        ans++;
    }
    printf("%lld",ans);
    return 0;
}