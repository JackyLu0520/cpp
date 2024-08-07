#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
struct node{
    int v,l,r;
}t[N];
int n,ans=0;
bool check(int l,int r){
    if(l==-1&&r==-1)    return 1;
    if((l==-1)!=(r==-1))    return 0;
    if(t[l].v!=t[r].v)  return 0;
    return check(t[l].l,t[r].r)&&check(t[l].r,t[r].l);
}
int cnt(int root){
    return root==-1?0:cnt(t[root].l)+cnt(t[root].r)+1;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&t[i].v);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&t[i].l,&t[i].r);
    for(int i=1;i<=n;i++)
        if(check(t[i].l,t[i].r))
            ans=max(ans,cnt(i));
    printf("%d",ans);
    return 0;
}