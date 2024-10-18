#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ans=0x3f3f3f3f;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int w,d;scanf("%d%d",&w,&d);
        ans=min(ans,w+(d-1)*7+1);
    }
    printf("%d",ans);
    return 0;
}