#include<bits/stdc++.h>
using namespace std;
int n,m,b1[1010][1010],s=0;
char b[1010][1010],b2[1010][1010];
int offset[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
void dfs(int x,int y){
    for(int i=0;i<4;i++){
        int tx=x+offset[i][0];
        int ty=y+offset[i][1];
        if(!b1[tx][ty]&&tx>0&&tx<=n&&ty>0&&ty<=m){
            b1[tx][ty]=1;
            s=(s+1)%10;
            dfs(tx,ty);
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        getchar();
        for(int j=1;j<=m;j++){
            b[i][j]=getchar();
            b2[i][j]=b[i][j];
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(b[i][j]=='*'){
                s=1;
                for(int i=1;i<=n;i++)
                    for(int j=1;j<=m;j++)
                        if(b[i][j]=='*')  b1[i][j]=1;
                        else              b1[i][j]=0;
                dfs(i,j);
                b2[i][j]=s+'0';
            }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            cout<<b2[i][j];
        cout<<endl;
    }
    return 0;
}
