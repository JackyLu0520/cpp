#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[1010],b[1010],f[1010][1010],sum;
int main(){
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	cin>>m;
	for(i=1;i<=m;i++)
		cin>>b[i];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i]==b[j])	f[i][j]=f[i-1][j-1]+1;
			else		f[i][j]=max(f[i-1][j],f[i][j-1]);
	cout<<f[n][m];
	return 0;
}
/*
Sample Input:
6
1 6 2 5 4 7
7
0 1 2 5 5 2 7
Sample Output:
4
*/
