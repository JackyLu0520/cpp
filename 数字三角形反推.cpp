#include<iostream>
#include<algorithm>
using namespace std;
int n,a[1001][1001]={0},f[1001][1001]={0},Max=0;
int main(){
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++)
			cin>>a[i][j];
	for(i=n;i>=1;i--)
		for(j=1;j<=i;j++)
			f[i][j]=(i==n)?a[i][j]:(max(f[i+1][j],f[i+1][j+1])+a[i][j]);
	cout<<f[1][1];
	return 0;
}
/*
Sample Input:
4
1
3 2
4 10 1
4 3 2 20

Sample Output:
24
*/
