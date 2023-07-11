#include<bits/stdc++.h>
using namespace std;
int offset[8][2]={{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
int n,m,b[410][410]={0},a[410][410],sx,sy,tx,ty;
struct node{
	int x,y,step;
	void set(int _x,int _y,int _step){
		x=_x;
		y=_y;
		step=_step;
	}
}t;
queue<node> q; 
int main(){
	cin>>n>>m>>sx>>sy;
	memset(a,-1,sizeof(a));
	t.set(sx,sy,0);
	q.push(t);
	a[sx][sy]=0;b[sx][sy]=1;
	while(!q.empty()){
		for(int i=0;i<8;i++){
			tx=q.front().x+offset[i][0];
			ty=q.front().y+offset[i][1];
			if(!b[tx][ty]&&tx>=1&&ty>=1&&tx<=n&&ty<=m){
				b[tx][ty]=1;
				t.set(tx,ty,q.front().step+1);
				q.push(t);
				a[tx][ty]=q.back().step;
			}
		}
		q.pop();
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			cout<<left<<setw(5)<<a[i][j];
		cout<<endl;
	}
	return 0;
}
