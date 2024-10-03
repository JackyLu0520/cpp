#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=2e5+10;
int n,m;
int l[N],r[N];
vector<int>tmp;
int b[2*N],ans=0;
int main(){
    freopen("interval.in","r",stdin);
    freopen("interval.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&l[i],&r[i]);
    l[0]=l[1],r[0]=r[1];
    for(int i=2;i<=m+1;i++)
        l[0]=max(l[0],l[i]),r[0]=min(r[0],r[i]);
    tmp.push_back(-0x3f3f3f3f);
    if(l[0]<=r[0])   tmp.push_back(l[0]),tmp.push_back(r[0]+1);
    for(int i=m+2;i<=n;i++)
        tmp.push_back(l[i]),tmp.push_back(r[i]+1);
    sort(tmp.begin(),tmp.end());
    tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
    if(l[0]<=r[0]){
        int x=lower_bound(tmp.begin(),tmp.end(),l[0])-tmp.begin();
        int y=lower_bound(tmp.begin(),tmp.end(),r[0]+1)-tmp.begin();
        b[x]++;b[y]--;
    }
    for(int i=m+2;i<=n;i++){
        int x=lower_bound(tmp.begin(),tmp.end(),l[i])-tmp.begin();
        int y=lower_bound(tmp.begin(),tmp.end(),r[i]+1)-tmp.begin();
        b[x]++;b[y]--;
    }
    for(int i=1;i<tmp.size();i++)
        b[i]+=b[i-1];
    for(int i=1;i<tmp.size();i++)
        if(b[i]){
            ans+=tmp[i+1]-tmp[i];
        }
    printf("%d",ans);
    return 0;
}