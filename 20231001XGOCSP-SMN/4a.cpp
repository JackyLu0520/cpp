//A:<2 L:连续<=3
#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int n,ans,rec[100010];//A:0 L:1 P:2
bool isA=0;
void dfs(int step){//step:1~n
    if(step>n){
        ans=(ans+1)%MOD;
        return;
    }
    if(!isA){
        isA=1;
        rec[step]=0;
        dfs(step+1);
        isA=0;
    }
    if(step<3||rec[step-1]!=1||rec[step-2]!=1){
        rec[step]=1;
        dfs(step+1);
    }
    rec[step]=2;
    dfs(step+1);
}
int main(){
    freopen("4b.cpp","w",stdout);
    for(int i=1;i<=100010;i++){
        n=i;
        ans=0;
        dfs(1);
        printf("%d,",ans);
    }
    return 0;
}