#include<iostream>
using namespace std;
int n,m,p,q,sx,sy,tx,ty;
int offset[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool b[51][51]={0},a[51][51]={0},flag=0;
int x[2501],y[2501],step[2501],head=1,tail=1;
int main(){
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>a[i][j];
	cin>>sx>>sy>>p>>q;
	x[tail]=sx;y[tail]=sy;step[tail]=0;tail++;b[sx][sy]=1;
	while(head<tail){
		for(i=0;i<4;i++){
			tx=x[head]+offset[i][0];
			ty=y[head]+offset[i][1];
			if(!b[tx][ty]&&!a[tx][ty]&&tx>=1&&tx<=n&&ty>=1&&ty<=m){
				x[tail]=tx;y[tail]=ty;step[tail]=step[head]+1;tail++;b[tx][ty]=1;
				if(tx==p&&ty==q){flag=1;break;}
			}
		}
		if(flag)	break;
		head++;
	}
	cout<<step[tail-1];
	return 0;
}
/*
ÊäÈë 
13 13 3 3
#############
#GG.GGG#GGG.#
###.#G#G#G#G#
#.......#..G#
#G#.###.#G#G#
#GG.GGG.#.GG#
#G#.#G#.#.#.#
##G...G.....#
#G#.#G###.#G#
#...G#GGG.GG#
#G#.#G#G#.#G#
#GG.GGG#G.GG#
#############
Êä³ö
7,11 10 

*/ 
