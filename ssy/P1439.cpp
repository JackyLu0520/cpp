#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
int a[N],b[N],c[N],d[N];
int f[N],len=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        d[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        c[i]=d[b[i]];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        if(c[i]>=f[len])    f[++len]=c[i];
        else                *upper_bound(f+1,f+len+1,c[i])=c[i];
    printf("%d",len);
    return 0;
}