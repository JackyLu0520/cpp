#include<bits/stdc++.h>
using namespace std;
bool a[3010][3010],b[3010][3010]={0};
struct Node{
	int x,y;
	Node(){}
	Node(int X,int Y):x(X),y(Y){}
};
vector<Node> nodes1,nodes2;
int offset[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int n,sx,sy,fx,fy,ans=0x3f3f3f3f;
void Bfs(int x,int y,bool mode){
	queue<Node> q;
	q.push(Node(x,y));
	b[x][y]=1;
	if(!mode)	nodes1.push_back(Node(x,y));
	else		nodes2.push_back(Node(x,y));
	while(q.size()){
		for(int i=0;i<4;i++){
			int tx=x+offset[i][0];
			int ty=y+offset[i][1];
			if(!b[tx][ty]&&!a[tx][ty]&&tx>=1&&tx<=n&&ty>=1&&ty<=n){
				b[tx][ty]=1;
				if(!mode)	nodes1.push_back(Node(tx,ty));
				else		nodes2.push_back(Node(tx,ty));
				q.push(Node(tx,ty));
			}
		}
		q.pop();
	}
}
int dis(Node a,Node b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int main(){
	cin>>n>>sx>>sy>>fx>>fy;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=getchar()-'0';
	Bfs(sx,sy,0);
	Bfs(fx,fy,1);
	for(int i=0;i<nodes1.size();i++)
		for(int j=0;j<nodes1.size();j++)
			ans=min(ans,dis(nodes1[i],nodes2[j]));
	cout<<ans;
	return 0;
} 
