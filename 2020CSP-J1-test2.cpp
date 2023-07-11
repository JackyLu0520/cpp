#include<bits/stdc++.h>
using namespace std;
const int MAXN =105;
const int MAXK =105;
int h[MAXN][MAXK];

int f(int n,int m){
	if(m==1)	return n;
	if(n==0)	return 0;
	int ret=2147483647;
	for(int i=1;i<=n;i++)
		ret=min(ret,max(f(n-i,m),f(i-1,m-1))+1);
	return ret;
}

int g(int n,int m){
	for(int i=1;i<=n;i++)	h[i][1]=i;
	for(int i=1;i<=m;i++)	h[0][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++){
			h[i][j]=2147483647;
			for(int k=1;k<=i;k++)
				h[i][j]=min(h[i][j],max(h[i-k][j],h[k-1][j-1])+1);
			cout<<h[i][j]<<" ";
		}
		cout<<endl;		
	}

	return h[n][m];
}

int main(){
	int n,m;
	cin>>n>>m;
	//cout<<f(n,m)<<endl;
	cout<<g(n,m)<<endl;
	return 0;
}