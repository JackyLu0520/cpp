#include<iostream>
using namespace std;
long long a[1010][1010],f[1010][1010]={0};
int n;
int main(){
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++)
			cin>>a[i][j];
	for(i=n;i>=1;i--)
		for(j=i;j>=1;j--)
			f[i][j]=max(f[i+1][j],f[i+1][j+1])+a[i][j];
	cout<<f[1][1];
	return 0;
} 
