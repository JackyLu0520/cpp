#include<bits/stdc++.h>
using namespace std;
const int N=1010,M=62;
int n,ans=0;
pair<int,long long> s[N];
long long b[M+1];
bool insert(long long x){
    for(int i=M;i>=0;i--)
        if((x>>i)==1){
            if(!b[i]){
                b[i]=x;return 1;
            }else   x^=b[i];
        }
    return 0;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        long long num;int m;scanf("%lld%d",&num,&m);
        s[i]=make_pair(m,num);
    }
    sort(s+1,s+n+1,greater<pair<int,long long>>());
    for(int i=1;i<=n;i++)
        if(insert(s[i].second))
            ans+=s[i].first;
    printf("%d",ans);
    return 0;
}