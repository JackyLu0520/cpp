//公式+乘法逆元（未完成）
#include<bits/stdc++.h>
using namespace std;
const int M=1010,MOD=1e9+7;
int binmul(int a,int b){
    int res=0;
    while(b){
        if(b&1) res=(res+a)%MOD;
        res=(res+res)%MOD;
        b>>=1;
    }
    return res;
}
int fact(int n){
    int res=1;
    for(int i=n;i>=1;i--)
        res=binmul(res,i);
    return res;
}
int rev(int a){
    int b=MOD-2,res=1;
    while(b){
        if(b&1) res=binmul(res,a);
        res=binmul(res,res);
        b>>=1;
    }
    return res;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n=0,m,a[M];
        scanf("%*d%d",&m);
        for(int i=0;i<m;i++){
            scanf("%d",&a[i]);
            n+=a[i];
        }
        int ans=fact(n);
        printf("#%d ",ans);
        for(int i=0;i<m;i++)
            ans=binmul(ans,rev(fact(a[i])));
        printf("%d\n",ans);
    }
    return 0;
}