#include<bits/stdc++.h>
using namespace std;
const int N=1010,M=1010;
int n,m;
int a[N][M],sx,sy,ex,ey;
int vis[N][M][2]={0},dis[N][M][2];
int dirs[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
struct node{
    int x,y,t;
    node(){}
    node(int X,int Y,int T){x=X;y=Y;t=T;}
};
queue<node>q;
int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]==2)  sx=i,sy=j;
            if(a[i][j]==3)  ex=i,ey=j;
        }
    memset(dis,0x3f,sizeof dis);
    q.push(node(sx,sy,0));
    dis[sx][sy][0]=0;
    while(!q.empty()){
        node u=q.front();q.pop();
        if(vis[u.x][u.y][u.t])  continue;
        vis[u.x][u.y][u.t]=1;
        for(int i=0;i<4;i++){
            int tx=u.x+dirs[i][0];
            int ty=u.y+dirs[i][1];
            if(tx<1||tx>n||ty<1||ty>m)  continue;
            if(a[tx][ty]==1)    continue;
            if(!vis[tx][ty][a[tx][ty]==4||u.t]){
                dis[tx][ty][a[tx][ty]==4||u.t]=dis[u.x][u.y][u.t]+1;
                q.push(node(tx,ty,a[tx][ty]==4||u.t));
            }
        }
        /*system("cls");
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
                printf("%12d",dis[i][j][0]);
            printf("\n");
        }
        printf("\n");
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
                printf("%12d",dis[i][j][1]);
            printf("\n");
        }
        printf("\n");
        system("pause");*/
    }
    /*    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
                printf("%12d",dis[i][j][0]);
            printf("\n");
        }
        printf("\n");
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
                printf("%12d",dis[i][j][1]);
            printf("\n");
        }
        printf("\n");
        system("pause");*/
    printf("%d",dis[ex][ey][1]);
    return 0;
}