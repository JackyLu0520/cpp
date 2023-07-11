#include<iostream>
using namespace std;
int sx,sy,fx,fy,cnt=0,b[6][6],n,m,t,bx,by;
int offset[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
void Dfs(int x,int y){
	if(x==fx&&y==fy){
		cnt++;
		return;
	}
	int i,tx,ty;
	for(i=0;i<4;i++){
		tx=x+offset[i][0];
		ty=y+offset[i][1];
		if(!b[tx][ty]&&tx>=1&&ty>=1&&tx<=n&ty<=m){
			b[tx][ty]=1;
			Dfs(tx,ty);
			b[tx][ty]=0;
		}
	}
}
int main(){
	int i,j;
	cin>>n>>m>>t;
	cin>>sx>>sy>>fx>>fy;
	for(i=1;i<=t;i++){
		cin>>bx>>by;
		b[bx][by]=1;
	}
	b[sx][sy]=1;
	Dfs(sx,sy);
	cout<<cnt;
	return 0;
} 
