#include<bits/stdc++.h>
using namespace std;
struct P{
	int x,y,dis;
	P(){}
	P(int X,int Y int DIS){
		x=X;
		y=Y;
		dis=DIS;
	}
};
bool cmp(P a,P b){
	return a.dis<b.dis;
}
priority_queue<P,cmp> q;
int m,n,a[110][110];
int dx[12]={1,0,-1, 0,0,2, 0,-2,1, 1,-1,-1};
int dy[12]={0,1, 0,-1,2,0,-2, 0,1,-1, 1,-1};
int dd[12]={1,1, 1, 1,2,2, 2, 2,2, 2, 2, 2};
int main(){
	cin>>m>>n;
	memset(a,-1,sizeof(a));
	while(n--){
		int x,y,c;
		cin>>x>>y>>c;
		a[x][y]=c;
	}
	while(!q.empty()){
		P head=q.top();
		q.pop();
		for(i=0;i<12;i++){
			int tx=head.x+dx[i];
			int ty=head.y+dy[i];
			int td=head.d+dd[i];
			if(a[tx][ty]==-1)	continue;
			if(tx==m&&ty==m){
				cout<<td;
				return 0;
			}
			q.push(P(tx,ty,td));
		}
	}
	
}