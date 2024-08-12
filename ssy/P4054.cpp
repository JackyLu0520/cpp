#include<bits/stdc++.h>
using namespace std;
const int N=310,M=310,C=110;
int n,m,a[N][M];
int t[N][M][C];
int lowbit(int x){return x&-x;}
void add(int x,int y,int c,int v){
    for(int i=x;i<=n;i+=lowbit(i))
        for(int j=y;j<=m;j+=lowbit(j))
            t[i][j][c]+=v;
}
int getsum(int x,int y,int c){
    int ans=0;
    for(int i=x;i;i-=lowbit(i))
        for(int j=y;j;j-=lowbit(j))
            ans+=t[i][j][c];
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            add(i,j,a[i][j],1);
        }
    int q;scanf("%d",&q);
    while(q--){
        int op;scanf("%d",&op);
        if(op==1){
            int x,y,c;
            scanf("%d%d%d",&x,&y,&c);
            add(x,y,a[x][y],-1);
            add(x,y,c,1);
            a[x][y]=c;
        }else{
            int x1,x2,y1,y2,c;
            scanf("%d%d%d%d%d",&x1,&x2,&y1,&y2,&c);
            printf("%d\n",getsum(x2,y2,c)-getsum(x2,y1-1,c)-getsum(x1-1,y2,c)+getsum(x1-1,y1-1,c));
        }
    }
    return 0;
}