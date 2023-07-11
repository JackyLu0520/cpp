#include<iostream>
#include<string>
using namespace std;
string word="LQBS";
int offset[4][2]={{1,0},{0,1},{-1,0},{0,-1}},n,m,num;
char a[110][110];int b[110][110]={0};
int flag;
bool loop;
void Dfs(int x,int y,int step){
	int tx,ty,i;
	if((step-1)%4==0){
		num++;flag++;
		for(i=0;i<4;i++){
			tx=x+offset[i][0];
			ty=y+offset[i][1];
			if(a[tx][ty]==word[0]&&tx>=1&&tx<=n&&ty>=1&&ty<=m){
				if(b[tx][ty])	{loop=1;return;}
				else{
					b[tx][ty]++;
					Dfs(tx,ty,step+1);
					if(step>flag*4)
						b[tx][ty]--;
				}
			}
		}
		return;
	}
	for(i=0;i<4;i++){
		tx=x+offset[i][0];
		ty=y+offset[i][1];
		if(a[tx][ty]==word[(step-1)%4]&&tx>=1&&tx<=n&&ty>=1&&ty<=m){
			b[tx][ty]++;
			Dfs(tx,ty,step+1);
			if(step>flag*4)
				b[tx][ty]--;
		}
	}
	return;
}
int main(){
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>a[i][j];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i][j]==word[0]&&!b[i][j]){
				flag=0,loop=0;
				b[i][j]++;
				Dfs(i,j,2);
				if(!flag)
					b[i][j]--;
			}
	cout<<(loop?-1:num);
	return 0;
}
/*
输入1 
1 2
LQ
输出1
0

输入2 
3 3
LSB
QBQ
BSL
输出2
-1

输入3 
4 4
BLQB
BBQS
SBQL
QQQQ
输出3
2

输入4
4 4
BLQB
BBQS
SSQL
QQQQ
输出4
1
*/ 
