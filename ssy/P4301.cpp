#include<bits/stdc++.h>
using namespace std;
const int N=105,M=30;
int n,a[N],b[M+1];
long long ans=0;
bool insert(int x){
    for(int i=M;i>=0;i--)
        if((x>>i)==1){
            if(!b[i]){
                b[i]=x;return 1;
            }else x^=b[i];
        }
    return 0;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1,greater<int>());
    for(int i=1;i<=n;i++)
        if(!insert(a[i]))
            ans+=a[i];
    printf("%lld",ans);
    return 0;
}