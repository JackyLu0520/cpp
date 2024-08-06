#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int main(){
    int n;
    scanf("%d",&n);
    int ans=0;
    for(int i=1;i<=n;i++){
        int t;
        scanf("%d",&t);
        ans=gcd(ans,abs(t));
    }
    printf("%d",ans);
    return 0;
}