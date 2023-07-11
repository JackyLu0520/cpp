#include<bits/stdc++.h>
using namespace std;
int x,y,mx,my;
bool b[22][22]={0};
long long dp[22][22]={0};
int main(){
	cin>>x>>y>>mx>>my;
	x+=1;y+=1;mx+=1;my+=1;
	b[mx][my]=1;
	if(mx+2<=x&&my+1<=y)	b[mx+2][my+1]=1;
	if(mx+2<=x&&my-1>=1)	b[mx+2][my-1]=1;
	if(mx-2>=1&&my+1<=y)	b[mx-2][my+1]=1;
	if(mx-2>=1&&my-1>=1)	b[mx-2][my-1]=1;
	if(mx+1<=x&&my+2<=y)	b[mx+1][my+2]=1;
	if(mx+1<=x&&my-2>=1)	b[mx+1][my-2]=1;
	if(mx-1>=1&&my+2<=y)	b[mx-1][my+2]=1;
	if(mx-1>=1&&my-2>=1)	b[mx-1][my-2]=1;
	for(int i=1;i<=x;i++)
		for(int j=1;j<=y;j++)
			if(b[i][j]==1)			dp[i][j]=0;
			else if(i==1&&j==1)		dp[i][j]=1;
			else					dp[i][j]=dp[i-1][j]+dp[i][j-1];
	cout<<dp[x][y];
	return 0;
}
