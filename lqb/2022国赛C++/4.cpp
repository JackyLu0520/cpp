#include<bits/stdc++.h>
using namespace std;
int n,offset[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int s,Max=0;
char a[60][60];
bool b[60][60];
void dfs(int x,int y){
	for(int i=0;i<4;i++){
		int tx=x+offset[i][0];
		int ty=y+offset[i][1];
		if(tx>0&&ty>0&&tx<=n&&ty<=n&&!b[tx][ty]&&a[tx][ty]=='A'){
			b[tx][ty]=1;
			s++;
			dfs(tx,ty);
		}
	}
}
int main(){
	cin>>n;
	getchar();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			a[i][j]=getchar();
			getchar();
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[i][j]=='B'){
				s=1;
				memset(b,0,sizeof(b));
				b[i][j]=1;
				dfs(i,j);
				Max=max(Max,s);
				//cout<<s<<' '<<Max<<' '<<i<<' '<<j<<endl;
			}
	cout<<Max;
	return 0;
}