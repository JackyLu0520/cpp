#include<bits/stdc++.h>
using namespace std;
int offset[4][2]={{1,0},{0,1},{0,-1},{-1,0}};
int m,n,cnt=0;
bool b[110][110]={0};
struct Node{
	int x,y,s;
	Node(){}
	Node(int X,int Y,int S){
		x=X;
		y=Y;
		s=S;
	}
};
queue<Node> q;
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++){
			char t;
			cin>>t;
			if(t=='O')	b[i][j]=1;
			if(t=='X')	{q.push(Node(i,j,0));cnt++;b[i][j]=1;}
		}
	while(!q.empty()&&q.front().s<3){
		for(int i=0;i<4;i++){
			int tx=q.front().x+offset[i][0];
			int ty=q.front().y+offset[i][1];
			if(!b[tx][ty]&&tx>=1&&tx<=m&&ty>=1&&ty<=m){
				q.push(Node(tx,ty,q.front().s+1));
				cnt++;
				b[tx][ty]=1;
			}
		} 
		q.pop();
	}
	cout<<cnt;
	return 0;
}
