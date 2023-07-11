#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=0;
char a[35][35];
bool check(int x1,int y1,int x2,int y2){
	for(int i=x1;i<=x2;i++)
		if(a[i][y2]!=a[x1][y1])
			return 0;
	for(int i=y1;i<=y2;i++)
		if(a[x2][i]!=a[x1][y1])
			return 0;
	return 1;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int x=i+1,y=j+1;check(i,j,x,y);x++,y++)
				cnt++;
	cout<<cnt;
	return 0;
}