#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=1e5+10;
long long n,m,l,maxv;
long long d[N],v[N],a[N];
long long p[M];
int cnt1,cnt2;
struct seg{
    int l,r;
    seg(){}
    seg(int _l,int _r){l=_l;r=_r;}
    bool operator < (const seg& a) const{
        return l<a.l;
    }
}s[N];
int main(){
    int _;
    scanf("%d",&_);
    while(_--){
        scanf("%lld%lld%lld%lld",&n,&m,&l,&maxv);
        for(int i=1;i<=n;i++)
            scanf("%lld%lld%lld",&d[i],&v[i],&a[i]);
        for(int i=1;i<=m;i++)
            scanf("%lld",&p[i]);
        cnt1=0;cnt2=0;
        sort(p+1,p+m+1);
        for(int i=1;i<=n;i++){
            int t=lower_bound(p+1,p+m+1,d[i])-p;
            if(a[i]==0){
                if(v[i]<=maxv)  continue;
                s[++cnt1]=seg(t,m);
                //printf("#%d:[%d,%d]\n",i,t,m);
                continue;
            }
            double x=(maxv*maxv-v[i]*v[i])*1.0/(2*a[i]);
            if(a[i]>0){
                if(v[i]*v[i]+2*a[i]*(p[m]-d[i])<=maxv*maxv)  continue;
                s[++cnt1]=seg(upper_bound(p+t,p+m+1,d[i]+x)-p,m);
            }else if(a[i]<0){
                if(v[i]*v[i]+2*a[i]*(p[t]-d[i])<=maxv*maxv)    continue;
                s[++cnt1]=seg(t,lower_bound(p+t,p+m+1,d[i]+x)-p-1);
            }
            //printf("#%d:[%d,%d]\n",i,s[cnt1].l,s[cnt1].r);
        }
        if(cnt1==0){printf("0 %lld\n",m);continue;}
        sort(s+1,s+cnt1+1);
        /*for(int i=1;i<=cnt1;i++)
            printf("[%d,%d] ",s[i].l,s[i].r);
        printf("\n");*/
        int r=m;
        for(int i=1;i<=cnt1;i++){
            if(r>=s[i].l)   r=min(r,s[i].r);
            else    cnt2++,r=s[i].r;
        }
        printf("%d %d\n",cnt1,m-cnt2-1);
    }
    return 0;
}