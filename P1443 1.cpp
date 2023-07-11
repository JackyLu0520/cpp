#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
int n,m,sx,sy,tx,ty;
int offset[8][2]={{1,2},{2,1},{1,-2},{2,-1},{-1,2},{-2,1},{-1,-2},{-2,-1}};
bool b[401][401],flag=0;
int a[401][401];
int x[160001],y[160001],step[160001],head=1,tail=1;
int main(){
	int i,j;
	cin>>n>>m>>sx>>sy;
	memset(a,-1,sizeof(a));
	x[tail]=sx;y[tail]=sy;step[tail]=0;tail++;b[sx][sy]=1;
	a[sx][sy]=0;
	while(head<tail){
		for(i=0;i<8;i++){
			tx=x[head]+offset[i][0];
			ty=y[head]+offset[i][1];
			if(!b[tx][ty]&&tx>=1&&tx<=n&&ty>=1&&ty<=m){
				x[tail]=tx;y[tail]=ty;step[tail]=step[head]+1;tail++;b[tx][ty]=1;
				a[tx][ty]=step[tail-1];
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
/*
3 3 1 1

0    3    2    
3    -1   1    
2    1    4    
*/ 
