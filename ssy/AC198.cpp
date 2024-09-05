#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull n,ans,ansnum=0,prime[16]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
void dfs(ull cur,ull m,ull num,ull x){
    if(cur>=16||m>n) return;
    if(num>ansnum){
        ans=m;ansnum=num;
    }
    if(num==ansnum&&m<ans)  ans=m;
    for(ull i=1;i<=x;i++){
        m*=prime[cur];
        if(m>n)  break;
        dfs(cur+1,m,num*(i+1),i);
    }
}
int main(){
    scanf("%llu",&n);
    dfs(0,1,1,60);
    printf("%llu",ans);
    return 0;
}