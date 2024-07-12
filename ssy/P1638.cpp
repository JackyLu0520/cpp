#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=2e3+10;
int n,m,a[N],ans,lans,rans;
int cnt[M]={1},c=1;
int main(){
    scanf("%d%d",&n,&m);ans=n+1;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int l=0,r=0;
    while(r<=n){
        cnt[a[l]]--;
        if(cnt[a[l]]==0)    c--;
        l++;
        while(r<=n&&c<m){
            r++;
            if(cnt[a[r]]==0)    c++;
            cnt[a[r]]++;
        }
        if(ans>r-l+1){ans=r-l+1;lans=l;rans=r;}
    }
    printf("%d %d",lans,rans);
    return 0;
}