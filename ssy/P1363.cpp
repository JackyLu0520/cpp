#include<bits/stdc++.h>
using namespace std;
const int N=1510,M=1510;
int n,m;
int a[N][M],vis[N][M][3];
int sx,sy;
int dirs[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
queue<tuple<int,int,int,int>>q;
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<n;i++){
            char t[M];
            scanf("%s",t);
            for(int j=0;j<m;j++){
                if(t[j]=='#')   a[i][j]=1;
                else            a[i][j]=0;
                if(t[j]=='S')   sx=i,sy=j;
            }
        }
        memset(vis,0,sizeof(vis));
        while(!q.empty())q.pop();
        bool flag=0;
        q.emplace(sx,sy,sx,sy);
        while(!q.empty()){
            int x,y,rx,ry;
            tie(x,y,rx,ry)=q.front();
            q.pop();
            if(vis[x][y][0]&&(rx!=vis[x][y][1]||ry!=vis[x][y][2])){
                flag=1;
                break;
            }
            if(vis[x][y][0]&&vis[x][y][1]==rx&&vis[x][y][2]==ry)    continue;
            vis[x][y][0]=1;vis[x][y][1]=rx;vis[x][y][2]=ry;
            for(int i=0;i<4;i++){
                int rtx=rx+dirs[i][0];
                int rty=ry+dirs[i][1];
                int tx=(rtx%n+n)%n;
                int ty=(rty%m+m)%m;
                if(a[tx][ty])   continue;
                q.emplace(tx,ty,rtx,rty);
            }
        }
        printf(flag?"Yes\n":"No\n");
    }
    return 0;
}