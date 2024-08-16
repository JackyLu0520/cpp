#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,ans=0;
int main(){
    scanf("%d%d%d%d",&n,&m,&a,&b);
    for(int i=1;i<=m;i++){
        int l;scanf("%d",&l);
        bool f=0;
        for(int j=1;j<=l;j++){
            int c;scanf("%d",&c);
            if(c==a)    f=1;
            if(c==b&&f==1)    ans++;
        }
    }
    printf("%d",ans);
    return 0;
}