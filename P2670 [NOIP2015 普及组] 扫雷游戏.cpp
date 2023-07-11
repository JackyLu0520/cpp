#include<bits/stdc++.h>
using namespace std;
int n,m,a[110][110]={0};
char c;
int main(){
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			cin>>c;
			if(c=='*')	a[i][j]=1;
		}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)
			if(a[i][j]==1)	cout<<'*';
			else	cout<<a[i-1][j-1]+
						a[i-1][j+1]+
						a[i+1][j-1]+
						a[i+1][j+1]+
						a[i][j-1]+
						a[i+1][j]+
						a[i][j+1]+
						a[i-1][j];
		cout<<endl;
	}
	return 0;
}
