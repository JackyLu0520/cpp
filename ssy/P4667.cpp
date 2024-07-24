#include<bits/stdc++.h>
using namespace std;
const int N=510,M=510;
int n,m;
char a[N][M];
struct node{
    int x,y;
    node(){}
    node(int X,int Y){x=X;y=Y;}
};
deque<node>q;
int vis[N][M]={0},dis[N][M];
int dirs[4][3]={{1,1,0},{-1,-1,0},{1,-1,1},{-1,1,1}};//0:\ 1:/
int dirs1[4][2]={{0,0},{-1,-1},{0,-1},{-1,0}};
void mypush(int x,int y,int w){
    if(w==0)    q.push_front(node(x,y));
    else        q.push_back(node(x,y));
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",a[i]);
    memset(dis,0x3f,sizeof dis);
    dis[0][0]=0;q.push_back(node(0,0));
    while(!q.empty()){
        node u=q.front();q.pop_front();
        if(vis[u.x][u.y])  continue;
        vis[u.x][u.y]=1;
        for(int i=0;i<4;i++){
            int tx=u.x+dirs[i][0];
            int ty=u.y+dirs[i][1];
            if(tx<0||tx>n||ty<0||ty>m)  continue;
            int tx1=u.x+dirs1[i][0];
            int ty1=u.y+dirs1[i][1];
            int w=dirs[i][2]!=int(a[tx1][ty1]=='/');
            //printf("(%d,%d)->(%d,%d):w=%d\n",u.x,u.y,tx,ty,w);
            if(dis[u.x][u.y]+w<dis[tx][ty]){
                dis[tx][ty]=dis[u.x][u.y]+w;
                if(!vis[tx][ty])
                    mypush(tx,ty,w);
            }
            /*printf("q:");
            for(deque<node>::iterator it=q.begin();it!=q.end();it++)
                printf("(%d,%d) ",it->x,it->y);
            printf("\n");*/
        }
    }
    /*for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++)
            printf("%12d",dis[i][j]);
        printf("\n");
    }*/
    if(dis[n][m]==0x3f3f3f3f)   printf("NO SOLUTION");
    else                        printf("%d",dis[n][m]);
    return 0;
}