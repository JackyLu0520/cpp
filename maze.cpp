#include<bits/stdc++.h>
using namespace std;
const int N=510,M=510,K=110;
int m,n,k;
bool a[M][N],b[M][N][K];
int dirs[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
struct node{int x,y,z,s;node(){}node(int X,int Y,int Z,int S){x=X;y=Y;z=Z;s=S;}};
queue<node>q;
int main(){
    scanf("%d%d%d",&m,&n,&k);
    for(int i=1;i<=m;i++){
        char s[110];
        scanf("%s",s);
        for(int j=0;j<n;j++)
            a[i][j+1]=s[j]-'0';
    }
    b[1][1][0]=1;q.push(node(1,1,0,0));
    while(!q.empty()){
        node c=q.front();q.pop();
        if(c.x==m&&c.y==n){
            printf("%d",c.s);
            return 0;
        }
        for(int i=0;i<4;i++){
            int tx=c.x+dirs[i][0];
            int ty=c.y+dirs[i][1];
            if(tx>m||ty>n||tx<1||ty<1)continue;
            if(!b[tx][ty][c.z]){
                if(a[tx][ty]){
                    if(c.z<k)
                        q.push(node(tx,ty,c.z+1,c.s+1));
                }else
                    q.push(node(tx,ty,c.z,c.s+1));
            }
        }
    }
    printf("No Answer");
    return 0;
}