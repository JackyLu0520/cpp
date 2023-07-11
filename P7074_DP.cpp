#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
long long a[1010][1010],f[1010][1010][2];
int main(){
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>a[i][j];
	for(i=0;i<=n+1;i++)
		for(j=0;j<=m;j++)
			f[i][j][0]=f[i][j][1]=-10000000000LL;
	for(j=1;j<=m;j++){
		for(i=1;i<=n;i++)
			if(i==1&&j==1)
				f[i][j][0]=a[i][j];
			else
				f[i][j][0]=max(f[i-1][j][0],max(f[i][j-1][0],f[i][j-1][1]))+a[i][j];
		if(j>1)
			for(i=n;i>=1;i--)
				f[i][j][1]=max(f[i+1][j][1],max(f[i][j-1][0],f[i][j-1][1]))+a[i][j];
	}
	cout<<max(f[n][m][0],f[n][m][1]);
	return 0;
}
/*
Sample Input 1:
3 4
1 -1 3 2
2 -1 4 -1
-2 2 -3 -1

Sample Output 1:
9

Sample Input 2:
2 5
-1 -1 -3 -2 -7
-2 -1 -4 -1 -2

Sample Output 2:
-10
*/
