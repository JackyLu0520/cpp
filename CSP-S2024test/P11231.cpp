#include<bits/stdc++.h>
using namespace std;
const int R=1e5+10;
int n;
int b[R]={0};
int ans=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int r;scanf("%d",&r);
        b[r]++;
    }
    for(int i=1;i<R;i++)
        ans=max(ans,b[i]);
    printf("%d",ans);
    return 0;
}