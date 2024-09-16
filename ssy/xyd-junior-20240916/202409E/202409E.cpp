#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,fa[N],ans=0;
void init(){for(int i=1;i<=n;i++)fa[i]=i;}
int query(int x){return fa[x]==x?x:fa[x]=query(fa[x]);}
void merge(int x,int y){fa[query(x)]=query(y);}
int main(){
    freopen("202409E.in","r",stdin);
    freopen("202409E.out","w",stdout);
    scanf("%d",&n);
    init();
    for(int i=1;i<=n;i++){
        int a;scanf("%d",&a);
        merge(i,a);
    }
    for(int i=1;i<=n;i++)
        if(fa[i]==i)
            ans++;
    printf("%d",ans);
    return 0;
}