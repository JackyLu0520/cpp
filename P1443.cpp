#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
int n,m,sx,sy,tx,ty,a[401][401],offset[8][2]={{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
bool b[401][401];
struct node{int x,y,s;}que[160001];int head,tail;
int main(){
	int i,j;
	cin>>n>>m>>sx>>sy;
	memset(a,-1,sizeof(a));
	head=tail=1;
	que[tail].x=sx;que[tail].y=sy;que[tail].s=0;tail++;
	a[sx][sy]=0;b[sx][sy]=1;
	while(head<tail){
		for(i=0;i<8;i++){
			tx=que[head].x+offset[i][0];
			ty=que[head].y+offset[i][1];
			if(!b[tx][ty]&&tx>=1&&ty>=1&&tx<=n&&ty<=m){
				b[tx][ty]=1;
				que[tail].x=tx;que[tail].y=ty;que[tail].s=que[head].s+1;tail++;
				a[tx][ty]=que[tail-1].s;
			}
		}
		head++;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)
			cout<<left<<setw(5)<<a[i][j];
		cout<<endl;
	}
	return 0;
}
