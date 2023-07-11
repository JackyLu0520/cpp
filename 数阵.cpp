#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[101][101]={0},f[101][101]={0};
int main(){
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>a[i][j];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			f[i][j]=(i==1&j==1)?a[1][1]:(max(f[i-1][j],f[i][j-1])+a[i][j]);
	cout<<f[n][m];
	return 0;
}
/*
input:
3 4
3 1 6 4
5 2 3 9
1 8 7 2

output:
27
*/
