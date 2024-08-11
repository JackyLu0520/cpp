#include<bits/stdc++.h>
using namespace std;
const int N=100010,T=1010;
int n,wmax;
int v[N],w[N],p=0;
int f[T];
bool b[N];
int main(){
    int tsh,tsm,teh,tem;
    scanf("%d:%d %d:%d %d",&tsh,&tsm,&teh,&tem,&n);
    wmax=teh*60+tem-tsh*60-tsm;
    for(int i=1;i<=n;i++){
        int tv,tw,tm,c=1;
        scanf("%d%d%d",&tw,&tv,&tm);
        if(tm==0){
            v[++p]=tv;
            w[p]=tw;
            b[p]=1;
            continue;
        }
        while(tm>=c){
            v[++p]=tv*c;
            w[p]=tw*c;
            b[p]=0;
            tm-=c;
            c*=2;
        }
        if(tm!=0){
            v[++p]=tv*tm;
            w[p]=tw*tm;
            b[p]=0;
        }
    }
    for(int i=1;i<=p;i++)
        if(b[i]==0){
            for(int j=wmax;j>=1;j--)
                if(j-w[i]>=0)
                    f[j]=max(f[j],f[j-w[i]]+v[i]);
        }
        else{
            for(int j=1;j<=wmax;j++)
                if(j-w[i]>=0)
                    f[j]=max(f[j],f[j-w[i]]+v[i]);
        }
    printf("%d",f[wmax]);
    return 0;
}