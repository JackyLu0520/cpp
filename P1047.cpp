#include<bits/stdc++.h>
using namespace std;
int l,m,ans=0;
bool b[10010]={0};
int main(){
    scanf("%d%d",&l,&m);
    while(m--){
        int u,v;
        scanf("%d%d",&u,&v);
        for(int i=u;i<=v;i++)
            b[i]=1;
    }
    for(int i=0;i<=l;i++)
        if(!b[i])    ans++;
    printf("%d",ans);
    return 0;
}