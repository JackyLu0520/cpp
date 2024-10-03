#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,k,a[N];
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int main(){
    freopen("coprime.in","r",stdin);
    freopen("coprime.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    while(m--){
        int op,x,y;scanf("%d%d%d",&op,&x,&y);
        if(op==1)   a[x]=y;
        else{
            int ans=0;
            for(int i=x;i+k-1<=y;i++){
                int j=i+k-1;bool f=1;
                for(int l=i;l<=j;l++)
                    for(int r=l+1;r<=j;r++)
                        if(gcd(a[l],a[r])>1){
                            f=0;break;
                        }
                ans+=f;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}