#include<bits/stdc++.h>
#define lowbit(x) (x)&(-(x))
using namespace std;
const int N=1e5+10;
//const int N=3e4+10;
//const int N=2010;
const int MOD=998244353;
int rd(){
   char s=getchar();int v=0;
   while(s<'0'||s>'9')s=getchar();
   while(s>='0'&&s<='9')v=v*10+s-'0',s=getchar();
   return v;
}
int n,a[N];
//long long dp[N][N];
struct BIT{
    vector<int>c;
    void clear(int size){
        c.resize(size+1);
        for(int i=1;i<=size;i++)
            c[i]=0;
    }
    void add(int i,long long k){
        for(;i<=n;i+=lowbit(i))
            c[i]=(c[i]+k)%MOD;
    }
    long long query(int i){
        long long ans=0;
        for(;i;i-=lowbit(i))
            ans=(ans+c[i])%MOD;
        return ans;
    }
};
vector<BIT>row,col;
int main(){
    int _;_=rd();
    while(_--){
        n=rd();
        for(int i=1;i<=n;i++)
            a[i]=rd();
        //memset(dp,0,sizeof(dp));
        row.resize(n+1);
        for(int i=1;i<=n;i++)
            row[i].clear(n);
        col.resize(n+1);
        for(int i=1;i<=n;i++)
            col[i].clear(n);
        for(int i=1;i<=n;i++){
            for(int l=1;l<a[i];l++){
                /*for(int r=l;r<a[i];r++){
                    dp[l][a[i]]+=dp[l][r];
                    dp[l][a[i]]%=MOD;
                }*/
                long long t=row[l].query(a[i]-1)-row[l].query(l-1);
                t=(t%MOD+MOD)%MOD;
                row[l].add(a[i],t);
                col[a[i]].add(l,t);
            }
            //dp[a[i]][a[i]]=1;
            row[a[i]].add(a[i],1);
            col[a[i]].add(a[i],1);
            for(int r=a[i]+1;r<=n;r++){
                /*for(int l=a[i]+1;l<=r;l++){
                    dp[a[i]][r]+=dp[l][r];
                    dp[a[i]][r]%=MOD;
                }*/
                long long t=col[r].query(r)-col[r].query(a[i]);
                t=(t%MOD+MOD)%MOD;
                row[a[i]].add(r,t);
                col[r].add(a[i],t);
            }
        }
        long long ans=0;
        /*for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
                ans=(ans+dp[i][j])%MOD;*/
        for(int i=1;i<=n;i++)
            ans=(ans+row[i].query(n))%MOD;
        printf("%lld\n",ans);
    }
    return 0;
}