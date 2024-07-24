#include<bits/stdc++.h>
using namespace std;
const int N=20;
int n,w,a[N],ans=20,vis[N];
void dfs(int step,int num,int m){
    if(step>n){
        ans=min(ans,num);
        return;
    }
    if(num>=ans) return;
    for(int i=1;i<=n;i++)
        if(!vis[i]){
            vis[i]=1;
            if(a[i]>m)  dfs(step+1,num+1,w-a[i]);
            else        dfs(step+1,num,m-a[i]);
            vis[i]=0;
        }
    return;
}
int main(){
    scanf("%d%d",&n,&w);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1,greater<int>());
    dfs(1,1,w);
    printf("%d",ans);
    return 0;
}