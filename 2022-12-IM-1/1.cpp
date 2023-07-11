#include<bits/stdc++.h>
using namespace std;
int m,n,a[1010][1010],cnt=0;
int main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++){
			if(a[i][j]!=2)	continue;
			for(int k=i;k>=1;k--){
				if(a[k][j]==1)
					a[k][j]=0;
				if(a[k][j]==3)
					break;
			}
			for(int k=i;k<=m;k++){
				if(a[k][j]==1)
					a[k][j]=0;
				if(a[k][j]==3)
					break;
			}
			for(int k=j;k>=1;k--){
				if(a[i][k]==1)
					a[i][k]=0;
				if(a[i][k]==3)
					break;
			}
			for(int k=j;k<=n;k++){
				if(a[i][k]==1)
					a[i][k]=0;
				if(a[i][k]==3)
					break;
			}
		}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			//cout<<a[i][j]<<' ';
			if(a[i][j]==1)
				cnt++;
		}
		//cout<<endl;
	}
	cout<<cnt;
	return 0;
}