#include<iostream>
#include<iomanip>
using namespace std;
int m,n,sx,sy,a[51][51],f[51][51],sum=0,offset[4][2]={{-1,0},{0,-1},{1,0},{0,1}},color=-1;
void Dfs(int x,int y,int c){
	int tx,ty,i;
	a[x][y]=c;
	for(i=0;i<4;i++){
		tx=x+offset[i][0];
		ty=y+offset[i][1];
		if(!f[tx][ty]&&a[tx][ty]>0&&tx>=1&&tx<=n&&ty>=1&&ty<=m){
			f[tx][ty]=1;
			Dfs(tx,ty,c);
		}
	}
}
int main(){
	int i,j;
	cin>>n>>m>>sx>>sy;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>a[i][j];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i][j]>0){
				f[i][j]=1;
				Dfs(i,j,color);
				color--;
			}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)
			cout<<setw(3)<<a[i][j];
		cout<<endl;
	}
	return 0;
}
