#include<bits/stdc++.h>
using namespace std;
int m,a[310][310],mx,my,mt,tx,ty;
int offset[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
bool b[310][310]={0};
struct node{
	int x,y,s;
	node(int _x,int _y,int _s){
		x=_x;
		y=_y;
		s=_s;
	}
};
queue<node> q;
int main(){
	cin>>m;
	for(int i=0;i<310;i++)
		for(int j=0;j<310;j++)
			a[i][j]=100000;
	for(int i=0;i<m;i++){
		cin>>mx>>my>>mt;
		if(mt<a[mx][my])	a[mx][my]=mt;
		for(int j=0;j<4;j++){
			tx=mx+offset[j][0];
			ty=my+offset[j][1];
			if(mt<a[tx][ty]&&tx>=0&&tx<302&&ty>=0&&ty<302)
				a[tx][ty]=mt;
		}
	}
	if(a[0][0]==0)	cout<<-1;
	else if(a[0][0]==100000)	cout<<0;
	else{
		q.push(node(0,0,0));
		b[0][0]=1;
		while(!q.empty()){
			for(int i=0;i<4;i++){
				tx=q.front().x+offset[i][0];
				ty=q.front().y+offset[i][1];
				if(!b[tx][ty]&&q.front().s+1<a[tx][ty]&&tx>=0&&ty>=0&&tx<=302&&ty<=302){
					q.push(node(tx,ty,q.front().s+1));
					b[tx][ty]=1;
					if(a[tx][ty]==100000){
						cout<<q.back().s;
						return 0;
					}
				}
			}
			q.pop();
		}
		cout<<-1;
	}
	return 0;
}
