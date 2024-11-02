#include<bits/stdc++.h>
using namespace std;
long long n;
long long prime[15]={2,3,5,7,11,13,17,19,23,29};
long long ans,anscnt;
void dfs(long long now,int pos,int last,int cnt){
    if(pos==10||now>n) return;
    if(cnt>anscnt)
        ans=now,anscnt=cnt;
    now*=prime[pos];
    for(int i=1;i<=last&&now<=n;i++){
        dfs(now,pos+1,i,cnt*(i+1));
        now*=prime[pos];
    }
}
int main(){
    scanf("%lld",&n);
    ans=n;
    dfs(1,0,1000000,1);
    printf("%lld",ans);
    return 0;
}