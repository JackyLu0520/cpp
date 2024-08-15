#include<bits/stdc++.h>
using namespace std;
int add(int x,int y){return y?add(x^y,(x&y)<<1):x;}
int main(){
    int n,sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        sum=add(sum,x);
    }
    printf("%d",sum);
    return 0;
}