#include<bits/stdc++.h>
using namespace std;
const int MAXR=1002;
int r,t[MAXR][MAXR],f[MAXR][MAXR]={0};
int main(){
	cin>>r;
	for(int i=1;i<=r;i++)
		for(int j=1;j<=i;j++)
			cin>>t[i][j];
	for(int i=r;i>=1;i--)
		for(int j=1;j<=i;j++)
			f[i][j]=max(f[i+1][j],f[i+1][j+1])+t[i][j];
	cout<<f[1][1];
	return 0;
}
