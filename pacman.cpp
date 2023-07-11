#include<bits/stdc++.h>
using namespace std;
int n,a[4][4],i,j;
int main(){
	freopen("pacman.in","r",stdin);
	freopen("pacman.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin>>a[i][j];
	if(n==1)
		cout<<a[1][1];
	else if(n==2)
		cout<<a[1][1]+a[1][2]+a[2][1]+a[2][2];
	else if(n==3){
		cout<<max(a[1][1]+a[1][3]+a[3][1]+a[2][2]+a[3][3],max(a[1][1]+a[1][2]+a[2][1]+a[2][2]+a[3][3]+a[2][3]+a[3][2],a[1][3]+a[1][2]+a[2][1]+a[2][2]+a[3][1]+a[2][3]+a[3][2]));
	}
	return 0;
}
