#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N];
int ans=1;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    if(n>m) printf("0\n");
    else{
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                ans=(ans*(abs(a[i]-a[j])%m))%m;
        printf("%d\n",ans);
    }
    return 0;
}