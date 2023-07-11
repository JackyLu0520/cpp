/*
5 4
5 3 5 3
1 5 3 0
2 3 5 1
6 1 1 5
1 5 5 4
*/
#include<cstdio>
using namespace std;
int n,m,a[51][51];
bool b[51][51],f=0;
struct node{int x,y;}s[2501];int top=0;
void Dfs(int x,int y,int front){
	int i;
	if(x==n&&y==m+1){
		f=1;
		for(i=1;i<=top;i++)
			printf("(%d,%d)",s[i].x,s[i].y);
		return;
	}
	if(!b[x][y]&&x>=1&&x<=n&&y>=1&&y<=m){
		b[x][y]=1;
		top++;
		s[top].x=x;
		s[top].y=y;
		if(a[x][y]==5||a[x][y]==6)
			switch(front){
				case 1:	Dfs(x,y+1,1);break;
				case 2:	Dfs(x+1,y,2);break;
				case 3:	Dfs(x,y-1,3);break;
				case 4:	Dfs(x-1,y,4);break;
			}
		if(a[x][y]>=1&&a[x][y]<=4)
			switch(front){
				case 1:	Dfs(x-1,y,4);Dfs(x+1,y,2);break;
				case 2:	Dfs(x,y-1,3);Dfs(x,y+1,1);break;
				case 3:	Dfs(x-1,y,4);Dfs(x+1,y,2);break;
				case 4:	Dfs(x,y-1,3);Dfs(x,y+1,1);break;
			}
		top--;
		b[x][y]=0;
	}
}
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	Dfs(1,1,1);
	printf(f?"":"impossible");
	return 0;
}
