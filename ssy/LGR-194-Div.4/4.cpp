#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10,M=1e3+10;
int n,m,ans=0;
int a[M],c[M];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        int b;
        scanf("%d",&b);
        c[b]++;
    }
    for(int i=1;i<=m;i++)
        if(a[i]*c[i]>a[ans]*c[ans])
            ans=i;
    printf("%d",ans);
    return 0;
}