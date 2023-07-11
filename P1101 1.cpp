#include<iostream>
#include<string>
using namespace std;
//char word[7]={'y','i','z','h','o','n','g'};
string word="yizhong";
int offset[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}},n;
char a[110][110];int b[110][110]={0};
bool flag;
void Dfs(int x,int y,int dir,int step){
	int tx,ty;
	if(step==8){
		flag=1;
		return;
	}
	tx=x+offset[dir][0];
	ty=y+offset[dir][1];
	if(a[tx][ty]==word[step-1]&&tx>=1&&tx<=n&&ty>=1&&ty<=n){
		flag=0;
		b[tx][ty]++;
		Dfs(tx,ty,dir,step+1);
		if(!flag)
			b[tx][ty]--;
	}
	return;
}
int main(){
	int i,j,k;
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin>>a[i][j];
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(a[i][j]==word[0])
				for(k=0;k<=7;k++){
					flag=0;
					b[i][j]++;
					Dfs(i,j,k,2);
					if(!flag)
						b[i][j]--;
				}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
			if(b[i][j])
				cout<<a[i][j];
			else
				cout<<'*';
		cout<<endl;
	}	
}
