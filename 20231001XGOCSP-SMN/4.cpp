//A:<2 L:连续<=3
#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int n,ans,rec[100010];//A:0 L:1 P:2
bool isA=0;
void dfs(int step){//step:1~n
    if(step>n){
        for(int i=1;i<=n;i++)
            printf("%d",rec[i]);
        printf("\n");
        ans=(ans+1)%MOD;
        return;
    }
    if(!isA){
        isA=1;
        rec[step]=0;
        dfs(step+1);
        isA=0;
    }else{
        printf("Err A:");
        for(int i=1;i<=step-1;i++)
            printf("%d",rec[i]);
        printf("0\n");
    }
    if(step<3||rec[step-1]!=1||rec[step-2]!=1){
        rec[step]=1;
        dfs(step+1);
    }else{
        printf("Err L:");
        for(int i=1;i<=step-1;i++)
            printf("%d",rec[i]);
        printf("1\n");
    }
    rec[step]=2;
    dfs(step+1);
}
int main(){
    scanf("%d",&n);
    dfs(1);
    printf("%d",ans);
    return 0;
}