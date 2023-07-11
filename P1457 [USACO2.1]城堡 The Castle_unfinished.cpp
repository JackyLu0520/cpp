#include<bits/stdc++.h>
using namespace std;
const int N=55;
int n,m;
struct wall{
	int x,y,dir;
	wall(){}
	wall(int X,int Y,int DIR){x=X;y=Y;dir=DIR;};
};
vector<wall> walls;
void floodfill(int x,int y){
	
}
int main(){
	cin>>m>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			int t;
			cin>>t;
			for(int dir=0;t;dir++){
				if(t&1)	walls.push_back(wall(i,j,dir));
				t>>=1;
			}
		}
	
}