#include<bits/stdc++.h>
using namespace std;
const int M=50,MOD=2008;
int n,m,cnt=0;
long long b[M+1]={0};
void insert(long long x){
    for(int i=M;i>=0;i--)
        if((x>>i)==1){
            if(b[i]==0){
                cnt++;b[i]=x;return;
            }else x^=b[i];
        }
}
int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++){
        long long x=0;char s[M+5];
        scanf("%s",s);
        for(int i=0;i<m;i++)
            x=(x<<1)|(s[i]=='O');
        insert(x);
    }
    printf("%lld",(1ll<<cnt)%MOD);
    return 0;
}