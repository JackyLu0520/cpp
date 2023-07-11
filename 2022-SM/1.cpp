#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;
bool a[110][110];
void dfs(int x,int y,int turns,bool d){
	//cout<<x<<' '<<y<<endl;
	if(x!=n-1&&y!=n-1&&turns==k)	return;
	if(turns>k)	return;
	if(x==n-1&&y==n-1){
		//cout<<turns<<endl;
		cnt++;
		return;
	}
	int tx=x+1,ty=y;
	if(!a[tx][ty]&&tx<n){
		if(d)	dfs(tx,ty,turns+1,0);
		else	dfs(tx,ty,turns,0);
	}
	tx=x,ty=y+1;
	if(!a[tx][ty]&&ty<n){
		if(!d)	dfs(tx,ty,turns+1,1);
		else	dfs(tx,ty,turns,1);
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		getchar();
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				if(getchar()=='H')	a[i][j]=1;
				else				a[i][j]=0;
			getchar();
		}
		/*
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				cout<<a[i][j]<<' ';
			cout<<endl;
		}*/
		cnt=0;
		if(!a[0][1])
			dfs(0,1,0,1);
		if(!a[1][0])
			dfs(1,0,0,0);
		cout<<cnt<<endl;
	}
	return 0;
}