#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,k,a[N],fa[N];
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++){
        int x,y;scanf("%d%d",&x,&y);
        fa[y]=x;
    }
    while(k--){
        int op,u;scanf("%d%d",&op,&u);
        if(op==1){
            int t;
            for(t=fa[u];gcd(a[t],a[u])==1&&t;t=fa[t]);
            printf("%d\n",t?t:-1);
        }else{
            int x;scanf("%d",&x);
            a[u]=x;
        }
    }
    return 0;
}