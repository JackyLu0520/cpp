#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,MOD=998244353;
int n,x[N],y[N],a[N],b[N];
int xmax=0,ymax=0;
int dirs[4][3][3]={
    {{0,0,1},{0,0,3},{0,1,2}},
    {{0,0,0},{0,0,2},{1,0,3}},
    {{0,0,1},{0,0,3},{0,-1,0}},
    {{0,0,0},{0,0,2},{-1,0,1}}
};
vector<vector<int>>dis[4][4],vis[4][4];
vector<vector<long long>>cnt[4][4];
void clear(){
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++){
            dis[i][j].resize(xmax+1);
            vis[i][j].resize(xmax+1);
            cnt[i][j].resize(xmax+1);
            for(int k=0;k<=xmax;k++){
                dis[i][j][k].resize(ymax+1);
                vis[i][j][k].resize(ymax+1);
                cnt[i][j][k].resize(ymax+1);
                for(int l=0;l<=ymax;l++){
                    dis[i][j][k][l]=0x3f3f3f3f;
                    vis[i][j][k][l]=0;
                    cnt[i][j][k][l]=0;
                }
            }
        }
}
struct node{
    int x,y,a;
    node(){}
    node(int _x,int _y,int _a){x=_x,y=_y,a=_a;}
};
queue<node>q;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d",&x[i],&y[i],&a[i],&b[i]);
        xmax=max(xmax,x[i]);ymax=max(ymax,y[i]);
    }
    clear();
    for(int j=0;j<4;j++){
        q.emplace(0,0,j);dis[j][j][0][0]=0;cnt[j][j][0][0]=1;
        while(!q.empty()){
            node u=q.front();q.pop();
            if(vis[j][u.a][u.x][u.y])   continue;
            vis[j][u.a][u.x][u.y]=1;
            for(int i=0;i<3;i++){
                node v(u.x+dirs[u.a][i][0],u.y+dirs[u.a][i][1],dirs[u.a][i][2]);
                if(v.x>xmax||v.x<0||v.y>ymax||v.y<0)    continue;
                if(dis[j][v.a][v.x][v.y]>dis[j][u.a][u.x][u.y]+1){
                    dis[j][v.a][v.x][v.y]=dis[j][u.a][u.x][u.y]+1;
                    cnt[j][v.a][v.x][v.y]=cnt[j][u.a][u.x][u.y];
                    q.emplace(v);
                }else if(dis[j][v.a][v.x][v.y]==dis[j][u.a][u.x][u.y]+1){
                    cnt[j][v.a][v.x][v.y]+=cnt[j][u.a][u.x][u.y];
                    cnt[j][v.a][v.x][v.y]%=MOD;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d %lld\n",dis[a[i]][b[i]][x[i]][y[i]],cnt[a[i]][b[i]][x[i]][y[i]]);
    return 0;
}