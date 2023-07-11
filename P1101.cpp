#include<iostream>
#include<cstring>
using namespace std;
char word[7]={'y','i','z','h','o','n','g'};
int offset[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}},n,i,j,k;
char a[110][110],b[110][110];
bool Dfs(int x,int y,int dir,int step){
	int tx,ty;
	if(step==8){
		return 1;
	}
	tx=x+offset[dir][0];
	ty=y+offset[dir][1];
	if(a[tx][ty]==word[step-1]&&tx>=1&&tx<=n&&ty>=1&&ty<=n){
		if(Dfs(tx,ty,dir,step+1)){
			b[tx][ty]=word[step-1];
			return 1;
		}
		return 0;
	}
	return 0;
}
int main(){
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			b[i][j]='*';
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin>>a[i][j];
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(a[i][j]==word[0])
				for(k=0;k<=7;k++)
					if(Dfs(i,j,k,2))
						b[i][j]=word[0];
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
			cout<<b[i][j];
		cout<<endl;
	}
}
