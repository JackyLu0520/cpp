#include<iostream>
using namespace std;
int n,m,p,q,sx=1,sy=1;
int offset[4][2]={{0,1},{1,0},{-1,0}};
bool b[1010][1010]={0};
int a[1010][1010]={0};
long long Max=-10000000000LL;
void Dfs(int x,int y,long long sum){
	int i,tx,ty;
	if(x==p&&y==q){
		if(sum>Max)	Max=sum;
		return;
	}
	for(i=0;i<3;i++){
		tx=x+offset[i][0];
		ty=y+offset[i][1];
		if(!b[tx][ty]&&tx>=1&&tx<=n&&ty>=1&&ty<=m){
			b[tx][ty]=1;
			Dfs(tx,ty,sum+a[tx][ty]);
			b[tx][ty]=0;
		}
	}
}
int main(){
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>a[i][j];
	p=n,q=m;
	b[sx][sy]=1;
	Dfs(sx,sy,a[sx][sy]);
	cout<<Max;
	return 0;
}
