#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,a[N];
int g[N],l[N],r[N];
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

int lg[N],st[N][18];
vector<int>p[N];

int main(){
    freopen("gcd.in","r",stdin);
    freopen("gcd.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    bool f=1;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&g[i],&l[i],&r[i]);
        if(l[i]!=r[i])    f=0;
    }
    if((n<=1000&&m<=1000)||f){//0-4
        for(int i=1;i<=m;i++){
            int ans[2]={0};
            for(int j=l[i];j<=r[i];j++)
                if(gcd(g[i],a[j])!=1)
                    ans[0]=max(ans[0],a[j]);
            if(ans[0]==0){printf("-1 -1\n");continue;}
            for(int j=l[i];j<=r[i];j++)
                if(a[j]==ans[0])
                    ans[1]++;
            printf("%d %d\n",ans[0],ans[1]);
        }
    }else{
        f=1;
        for(int i=1;i<=n;i++)
            if(a[i]%2!=0)
                f=0;
        for(int i=1;i<=m;i++)
            if(g[i]%2!=0)
                f=0;
        if(f){//5-6
            for(int i=2;i<=n;i++)
                lg[i]=lg[i>>1]+1;
            for(int i=1;i<=n;i++)
                p[a[i]].push_back(i);
            for(int i=1;i<=n;i++)
                st[i][0]=a[i];
            for(int j=1;j<18;j++)
                for(int i=1;i<=n;i++)
                    st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
            for(int i=1;i<=m;i++){
                int ans[2];
                int t=lg[r[i]-l[i]+1];
                ans[0]=max(st[l[i]][t],st[r[i]-(1<<t)+1][t]);
                auto lit=lower_bound(p[ans[0]].begin(),p[ans[0]].end(),l[i]);
                auto rit=upper_bound(p[ans[0]].begin(),p[ans[0]].end(),r[i]);
                ans[1]=rit-lit;
                printf("%d %d\n",ans[0],ans[1]);
            }
        }else{//7-9bf
            for(int i=1;i<=m;i++){
                int ans[2]={0};
                for(int j=l[i];j<=r[i];j++)
                    if(gcd(g[i],a[j])!=1)
                        ans[0]=max(ans[0],a[j]);
                if(ans[0]==0){printf("-1 -1\n");continue;}
                for(int j=l[i];j<=r[i];j++)
                    if(a[j]==ans[0])
                        ans[1]++;
                printf("%d %d\n",ans[0],ans[1]);
            }
        }
    }
    return 0;
}