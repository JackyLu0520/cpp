#include<bits/stdc++.h>
//#define getchar getchar_unlocked
//#define putchar putchar_unlocked
using namespace std;
constexpr int N=2e5+10,L=61,MOD=1e9+7;
long long nxt[N][L];//%n
long long step[N][L];//%MOD
bool s[N];
inline long long read(){
    long long sgn=1,ret=0;
    char c;
    do{c=getchar();if(c=='-')sgn=-1;}while(!isdigit(c));
    do{
        ret=(ret<<3)+(ret<<1)+(c^48);
        c=getchar();
    }while(isdigit(c));
    return sgn*ret;
}
inline void reads(bool a[]){
    char c;
    int tot=-1;
    do{c=getchar();}while(!isdigit(c));
    do{
        a[++tot]=c^48;
        c=getchar();
    }while(isdigit(c));
}
void write(long long x,bool f=1){
    if(x==0){if(f)putchar('0');return;}
    write(x/10,0);
    putchar((x%10)^48);
}
int main(){
    freopen("kingdom.in","r",stdin);
    freopen("kingdom.out","w",stdout);
    const long long n=read(),m=read();
    long long q=read();
    reads(s);
    long long last=0,Min=min(m,n);
    for(last=0;!s[(m-last)%n]&&last<Min;++last);
    if(last==Min) last=-1;
    for(long long i=0;i<n;++i){
        nxt[i][0]=(last==-1)?(i+1)%n:(i+m-last)%n;
        step[i][0]=(last==-1)?1:(m-last)%MOD;
        //test
        //printf("%lld %lld %lld\n",last,nxt[i][0],step[i][0]);
        //
        if(last!=-1)++last;
        if(s[(i+1+m)%n])  last=0;
        if(last==Min) last=-1;
    }
    for(int j=1;j<L;++j)
        for(int i=0;i<n;++i){
            nxt[i][j]=nxt[nxt[i][j-1]][j-1];
            step[i][j]=(step[i][j-1]+step[nxt[i][j-1]][j-1])%MOD;
        }
    while(q--){
        long long st,k,ans;
        st=read()-1,k=read();
        ans=st%MOD;
        long long now=st%n;
        for(int i=0;k;++i){
            if(k&1){
                ans=(ans+step[now][i])%MOD;
                now=nxt[now][i];
            }
            k>>=1;
        }
        write(ans+1);
        putchar('\n');
    }
#ifdef T
    fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
    return 0;
}