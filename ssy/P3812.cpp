#include<bits/stdc++.h>
using namespace std;
const int M=50;
int n;
long long b[M+1]={0};
void insert(long long x){
    for(int i=M;i>=0;i--)
        if((x>>i)==1){
            if(b[i]==0){
                b[i]=x;return;
            }else x^=b[i];
        }
}
long long query(){
    long long ans=0;
    for(int i=M;i>=0;i--)
        ans=max(ans,ans^b[i]);
    return ans;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        long long x;
        scanf("%lld",&x);
        insert(x);
    }
    printf("%lld",query());
    return 0;
}