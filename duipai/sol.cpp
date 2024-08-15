#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m;
int a[N],p;
int main(){
    freopen("data.in","r",stdin);
    freopen("sol.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    p=n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<p;j++)
            a[j]=max(a[j],a[j+1]);
        p--;
    }
    for(int i=1;i<=n-m-1;i++){
        for(int j=1;j<p;j++)
            a[j]=min(a[j],a[j+1]);
        p--;
    }
    printf("%d",a[p]);
    return 0;
}