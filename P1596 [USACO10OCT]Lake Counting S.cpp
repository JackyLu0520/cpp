#include<bits/stdc++.h>
using namespace std;
int cnt=0,m,n,a[110][110],f[110][110],sum=0,offset[8][2]={{-1,0},{0,-1},{1,0},{0,1},{-1,1},{1,-1},{1,1},{-1,-1}};
void Dfs(int x,int y){
	int tx,ty,i;
	for(i=0;i<8;i++){
		tx=x+offset[i][0];
		ty=y+offset[i][1];
		if(!f[tx][ty]&&a[tx][ty]>0&&tx>=1&&tx<=n&&ty>=1&&ty<=m){
			f[tx][ty]=1;
			Dfs(tx,ty);
		}
	}
}
int main(){
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		getchar();
		for(j=1;j<=m;j++){
			if(getchar()=='W')
				a[i][j]=1;
			else
				a[i][j]=0;
		}
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i][j]==1&&f[i][j]==0){
				f[i][j]=1;
				Dfs(i,j);
				cnt++;
			}
	cout<<cnt;
	return 0;
}
