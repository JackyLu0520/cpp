#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10,M=1e3+10;
int n,m,a[N][M],vis[N][M];//a: 1:empty 0:block 2:homework
int b[N][M][4];//b: 0:up 1:right 2:down 3:left
int dirs[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
vector<int> vl[N],vc[N];
struct node{int x,y,s;node(){}node(int X,int Y,int S){x=X;y=Y;s=S;}};
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)   vl[i].push_back(0);
    for(int i=1;i<=m;i++)   vc[i].push_back(0);
    for(int i=1;i<=n;i++){
        char t[M];
        scanf("%s",t);
        for(int j=0;j<strlen(t);j++)
            if(t[j]=='$'||t[j]=='.')
                a[i][j+1]=1;
            else if(t[j]=='X'){
                a[i][j+1]=0;
                vl[i].push_back(j+1);
                vc[j+1].push_back(i);
            }
            else if(t[j]=='#')
                a[i][j+1]=2;
    }
    for(int i=1;i<=n;i++)   vl[i].push_back(m+1);
    for(int i=1;i<=m;i++)   vc[i].push_back(n+1);
    for(int i=1;i<=n;i++){
        int k=0;
        for(int j=1;j<=m;j++){
            if(j>=vl[i][k+1])    k++;
            b[i][j][3]=j-vl[i][k];
        }
        k++;
        for(int j=m;j>=1;j--){
            if(j<=vl[i][k-1])    k--;
            b[i][j][1]=vl[i][k]-j;
        }
    }
    for(int j=1;j<=m;j++){
        int k=0;
        for(int i=1;i<=n;i++){
            if(i>=vc[j][k+1])    k++;
            b[i][j][0]=i-vc[j][k];
        }
        k++;
        for(int i=n;i>=1;i--){
            if(i<=vc[j][k-1])    k--;
            b[i][j][2]=vc[j][k]-i;
        }
    }/*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            printf("%d",b[i][j][0]);
        printf("\n");
    }
    printf("\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            printf("%d ",b[i][j][0]);
        printf("\n");
    }
    printf("\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            printf("%d ",b[i][j][1]);
        printf("\n");
    }
    printf("\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            printf("%d ",b[i][j][2]);
        printf("\n");
    }
    printf("\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            printf("%d ",b[i][j][3]);
        printf("\n");
    }
    printf("\n");*/
    queue<node>q;
    q.push(node(1,1,0));vis[1][1]=1;
    while(!q.empty()){
        node t=q.front();q.pop();
        if(a[t.x][t.y]==2){
            printf("%d",t.s);
            return 0;
        }
        for(int i=0;i<4;i++){
            int k=1;
            while(abs(dirs[i][0]*k)<b[t.x][t.y][i]&&
            abs(dirs[i][1]*k)<b[t.x][t.y][i]){
                int tx=t.x+dirs[i][0]*k;
                int ty=t.y+dirs[i][1]*k;
                if(!vis[tx][ty]){
                    //printf("%d %d %d->%d %d %d\n",t.x,t.y,t.s,tx,ty,t.s+1);//debug
                    q.push(node(tx,ty,t.s+1));
                    vis[tx][ty]=1;
                }
                k*=2;
            }
        }
    }
    printf("-1");
    return 0;
}