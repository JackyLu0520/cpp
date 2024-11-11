#include<bits/stdc++.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
using namespace std;
const int MOD1=1e9+7,MOD2=998244353;
const int N=110,M=1e6+10;
int n,m;
struct pll{
    long long a,b;
    pll(){}
    pll(int _a,int _b){a=_a;b=_b;}
};
inline pll read(){
    long long sgn=1,x1=0,x2=0;char c;
    do{
        c=getchar();
        if(c=='-')
            sgn=-1;
    }while(!isdigit(c));
    do{
        x1=((x1<<3)+(x1<<1)+(c^48))%MOD1;
        x2=((x2<<3)+(x2<<1)+(c^48))%MOD2;
        c=getchar();
    }while(isdigit(c));
    return pll(sgn*x1,sgn*x2);
}
void write(int x,bool f=1){
    if(x==0){
        if(f){putchar('0');putchar('\n');}
        return;
    }
    write(x/10,0);
    putchar(x%10+'0');
    if(f)putchar('\n');
}
int a1[N],a2[N];
inline long long f(int x,int a[],const int mod){
    long long ans=a[n];
    for(int i=n-1;i>=0;i--)
        ans=(ans*x+a[i])%mod;
    return ans;
}
int cnt=0,res[M];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++){
        pll t=read();
        a1[i]=t.a;a2[i]=t.b;
    }
    for(int i=1;i<=m;i++)
        if(!f(i,a1,MOD1)&&!f(i,a2,MOD2))
            res[++cnt]=i;
    write(cnt);
    for(int i=1;i<=cnt;i++)
        write(res[i]);
    return 0;
}