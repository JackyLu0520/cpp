#include<iostream>
using namespace std;
int m,p,q,sx=0,sy=0,tx,ty,mx,my,mt;
int offset[4][2]={{0,1},{1,0},{0,-1},{-1,0}},a[302][302];
bool b[302][302]={0},flag=0;
int x[91204],y[91204],step[91204],head=0,tail=0;
int main(){
	int i,j;
	cin>>m;
	for(i=0;i<302;i++)
		for(j=0;j<302;j++)
			a[i][j]=10000;
	for(i=0;i<m;i++){
		cin>>mx>>my>>mt;
		if(mt<a[mx][my])	a[mx][my]=mt;
		for(j=0;j<4;j++){
			tx=mx+offset[j][0];
			ty=my+offset[j][1];
			if(mt<a[tx][ty]&&tx>=0&&tx<302&&ty>=0&&ty<302)
				a[tx][ty]=mt;
		}
	}
	if(a[sx][sy]==0)			cout<<-1;
	else if(a[sx][sy]==10000)	cout<<0;
	else{
		x[tail]=sx;y[tail]=sy;step[tail]=0;tail++;b[sx][sy]=1;
		while(head<tail){
			for(i=0;i<4;i++){
				tx=x[head]+offset[i][0];
				ty=y[head]+offset[i][1];
				if(!b[tx][ty]&&step[head]+1<a[tx][ty]&&tx>=0&&tx<302&&ty>=0&&ty<302){
					x[tail]=tx;y[tail]=ty;step[tail]=step[head]+1;tail++;b[tx][ty]=1;
					if(a[tx][ty]==10000){flag=1;break;}
				}
			}
			if(flag)	break;
			head++;
		}
		if(head!=tail)	cout<<step[tail-1];
		else		cout<<-1;
	}
	return 0;
}
/*
4
0 0 2
2 1 2
1 1 2
0 3 5
*/
