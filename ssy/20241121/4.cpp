#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct dsu{
    int fa[N];
    dsu(int n){for(int i=1;i<=n;i++)fa[i]=i;}
    int query(int x){return fa[x]==x?x:fa[x]=query(fa[x]);}
    void merge(int x,int y){fa[query(x)]=query(y);}
};
int n,q;
int main(){
    scanf("%d%d",&n,&q);
    dsu d(n);
    while(q--){
        int op;scanf("%d",&op);
        if(op==1){
            int l,r;scanf("%d%d",&l,&r);
            for(int i=l,j=r;i<j;i++,j--)
                d.merge(i,j);
        }else{
            int l1,r1,l2,r2;scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
            if(r1-l1!=r2-l2){
                printf("Not equal\n");
                continue;
            }
            bool f=1;
            for(int i=l1,j=l2;i<=r1&&j<=r2;i++,j++)
                if(d.query(i)!=d.query(j)){
                    f=0;break;
                }
            printf(f?"Equal\n":"Unknown\n");
        }
    }
    return 0;
}