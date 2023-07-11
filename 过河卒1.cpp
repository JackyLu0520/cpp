#include<iostream>
using namespace std;
int main(){
	int x,y,mx,my,offset[8][2]={{2,1},{1,2},{-2,1},{-1,2},{2,-1},{1,-2},{-2,-1},{-1,-2}},i,j;
	long long a[21][21]={0};
	cin>>x>>y>>mx>>my;
	a[mx][my]=1;
	for(i=0;i<8;i++)
		if((mx+offset[i][0]>=0)&&(mx+offset[i][0]<=x)&&(my+offset[i][1]>=0)&&(my+offset[i][1]<=y))
			a[mx+offset[i][0]][my+offset[i][1]]=1;
	for(i=0;i<=x;i++)
		for(j=0;j<=y;j++)
			if(a[i][j]==1)		a[i][j]=0;
			else if(i==0&&j==0)	a[i][j]=1;
			else if(i==0)		a[i][j]=a[i][j-1];
			else if(j==0)		a[i][j]=a[i-1][j];
			else				a[i][j]=a[i][j-1]+a[i-1][j];
	cout<<a[x][y];
	return 0;
}
