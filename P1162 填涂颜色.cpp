#include<bits/stdc++.h>
using namespace std;
int n,a[51][51],f[51][51],next[4][2]={{-1,0},{0,-1},{1,0},{0,1}},color=-1;
void Dfs(int x,int y,int c){
	int tx,ty,i;
	a[x][y]=c;
	for(i=0;i<4;i++){
		tx=x+next[i][0];
		ty=y+next[i][1];
		if(!f[tx][ty]&&a[tx][ty]==2&&tx>=1&&tx<=n&&ty>=1&&ty<=n){
			f[tx][ty]=1;
			Dfs(tx,ty,c);
		}
	}
}
int main(){
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]==0)
				a[i][j]=2;
		}
	for(i=1;i<=n;i++){
		if(a[i][1]==2)
			Dfs(i,1,0);
		if(a[i][n]==2)
			Dfs(i,n,0);
	}
	for(i=1;i<=n;i++){
		if(a[1][i]==2)
			Dfs(1,i,0);
		if(a[n][i]==2)
			Dfs(n,i,0);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
			cout<<a[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}
