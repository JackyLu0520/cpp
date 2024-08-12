#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,d;
struct point{int x,y;}a[N];
int sqdis(point a,point b){return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}
int head[N],nxt[2*N*N],ver[2*N*N],tot=1;
void add(int u,int v){ver[++tot]=v;nxt[tot]=head[u];head[u]=tot;}
struct dsu{
    int fa[N];
    dsu(){for(int i=1;i<=n;i++)fa[i]=i;}
    int query(int x){return fa[x]==x?x:fa[x]=query(fa[x]);}
    void merge(int x,int y){fa[query(x)]=query(y);}
};
bool b[N]={0};
int main(){
    scanf("%d%d",&n,&d);dsu D;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].x,&a[i].y);
        for(int j=1;j<i;j++)
            if(sqdis(a[i],a[j])<=d*d){
                add(i,j);add(j,i);
            }
    }
    getchar();
    char op;
    while((op=getchar())!=EOF){
        if(op=='O'){
            int p;
            scanf("%d",&p);
            b[p]=1;
            for(int i=head[p];i;i=nxt[i])
                if(b[ver[i]])
                    D.merge(p,ver[i]);
        }else{
            int p,q;
            scanf("%d%d",&p,&q);
            printf((D.query(p)==D.query(q))?"SUCCESS\n":"FAIL\n");
        }
        getchar();
    }
    return 0;
}