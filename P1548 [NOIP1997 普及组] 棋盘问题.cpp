#include<bits/stdc++.h>
using namespace std;
int n,m,sq,rect;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(i==j)	sq+=(n-i+1)*(m-j+1);
			else		rect+=(n-i+1)*(m-j+1);
	cout<<sq<<' '<<rect;
	return 0;
}