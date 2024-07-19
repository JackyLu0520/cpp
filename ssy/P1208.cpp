#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int n,m,ans=0;
pair<int,int> f[N];
int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++){
        int p,a;
        scanf("%d%d",&p,&a);
        f[i]=make_pair(p,a);
    }
    sort(f+1,f+n+1);
    for(int i=1;i<=n;i++)
        if(f[i].second>=m){
            ans+=f[i].first*m;
            break;
        }
        else{
            ans+=f[i].first*f[i].second;
            m-=f[i].second;
        }
    printf("%d",ans);
    return 0;
}