#include<iostream>
using namespace std;
int n,m,p,q,cnt=0,sx,sy,t,bx,by;
int offset[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool b[51][51]={0},a[51][51]={0}; 
void Dfs(int x,int y,int step){
	int i,tx,ty;
	if(x==p&&y==q){
		cnt++;
		return;
	}
	for(i=0;i<4;i++){
		tx=x+offset[i][0];
		ty=y+offset[i][1];
		if(!b[tx][ty]&&!a[tx][ty]&&tx>=1&&tx<=n&&ty>=1&&ty<=m){
			b[tx][ty]=1;
			Dfs(tx,ty,step+1);
			b[tx][ty]=0;
		}
	}
}
int main(){
	int i,j;
	cin>>n>>m>>t;
	cin>>sx>>sy>>p>>q;
	for(i=1;i<=t;i++){
		cin>>bx>>by;
		a[bx][by]=1;
	}
	b[sx][sy]=1;
	Dfs(sx,sy,0);
	cout<<cnt;
	return 0;
}
/*
5 4
0 0 1 0
0 0 0 0
0 0 1 0
0 1 0 0
0 0 0 1
1 1 4 3

7
*/ 
