#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,ans=0;
double c[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        c[i]=1.0*b/a;
        if(c[ans]<c[i]) ans=i;
    }
    printf("%d",ans);
    return 0;
}