#include<bits/stdc++.h>
#define int __int128
using namespace std;
const int N=5e5+10;
int n,r,k,d[N];

template<class T>
T read(){
    T sgn=1,n=0;
    char c;
    do{c=getchar();if(c=='-')sgn=-1;}while(!isdigit(c));
    while(isdigit(c)){
        n=(n<<1)+(n<<3)+c-'0';
        c=getchar();
    }
    return sgn*n;
}
template<class T>
void write(T n,bool flag=1){
    if(n<(int)0){putchar('-');n=-n;}
    if(n==(int)0){if(flag)putchar('0');return;}
    write(n/10,0);
    putchar(n%10+'0');
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a>b?a:b;}


bool check(int x){
    int t[N],cur=(int)0,cnt=k;
    memcpy(t,d,sizeof(d));
    for(int i=1;i<=n;i++){
        cur+=t[i];
        if(cur<x){
            t[i]+=x-cur;
            t[min(i+2*r,n)+(int)1]-=x-cur;
            cnt-=x-cur;
            cur=x;
        }
    }
    return cnt>=0;
}
signed main(){
    n=read<int>(),r=read<int>(),k=read<int>();
    for(int i=1;i<=n;i++){
        int a=read<int>();
        d[max(i-r,(int)1)]+=a;
        d[min(i+r,n)+1]-=a;
    }
    int l=0,r=(int)1e18+(int)5e14;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(check(mid))  l=mid;
        else            r=mid-1;
    }
    write(l);
    return 0;
}