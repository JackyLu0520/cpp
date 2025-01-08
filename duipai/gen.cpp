#include<bits/stdc++.h>
using namespace std;
const int N=20,M=20,A=20;
mt19937 Rand(chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count());
inline int randint(int l,int r){
    return Rand()%(r-l+1)+l;
}
struct dsu{
    int fa[N];
    dsu(int n){for(int i=1;i<=n;i++)fa[i]=i;}
    int query(int x){return fa[x]==x?x:fa[x]=query(fa[x]);}
    void merge(int x,int y){fa[query(x)]=query(y);}
};
int main(){
    int n=randint(1,N),m=randint(1,M);
    printf("%d %d\n",n,m);
    dsu d(n);
    for(int i=1;i<n;i++){
        int u,v;
        do
            u=randint(1,n),v=randint(1,n);
        while(d.query(u)==d.query(v));
        printf("%d %d\n",u,v);
        d.merge(u,v);
    }
    for(int i=1;i<=m;i++)
        printf("%d %d %d\n",randint(1,n),randint(1,n),randint(1,A));
    return 0;
}