#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,S=4e5+10;
int n,k;
int head[N+S],nxt[S],ver[S],etot=1,vtot=n;
long long ew[S];
inline int newv(){return ++vtot;}
inline void add(int u,int v,long long w){
    ver[++etot]=v;ew[etot]=w;nxt[etot]=head[u];head[u]=etot;
}
long long dis[N+S];

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++){
        int sz;scanf("%d",&sz);
        int x=newv();
        while(sz--){
            int t,w;
            scanf("%d%lld",&t,&w);
            add(x,t,w);
            add(t,x,w);
        }
    }

}