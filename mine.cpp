#include<bits/stdc++.h>
using namespace std;
int n,m,a[102][102]={0},i,j;
char c;
int main(){
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			cin>>c;
			if(c=='*')
				a[i][j]=1;
		}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)
			if(a[i][j]==0)
				cout<<a[i-1][j-1]
				      +a[i-1][j]
				      +a[i-1][j+1]
				      +a[i][j-1]
				      +a[i][j+1]
				      +a[i+1][j-1]
			          +a[i+1][j]
				      +a[i+1][j+1];
			else
				cout<<'*';
		cout<<endl;
	}
	return 0;
}
