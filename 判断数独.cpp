#include<bits/stdc++.h>
using namespace std;
int a[10][10],b[10];
int main(){
	int i,j,k,l;
	for(i=1;i<=9;i++)
		for(j=1;j<=9;j++)
			cin>>a[i][j];
	for(i=1;i<=9;i++){
		memset(b,0,sizeof(b));
		for(j=1;j<=9;j++)
			if(b[a[i][j]]==0)
				b[a[i][j]]=1;
			else{
				cout<<"No";
				return 0;
			}
	} 
	for(i=1;i<=9;i++){ 
		memset(b,0,sizeof(b));
		for(j=1;j<=9;j++)
			if(b[a[j][i]]==0)
				b[a[j][i]]=1;
			else{
				cout<<"No";
				return 0;
			}
	} 
	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++){
			memset(b,0,sizeof(b));
			for(k=1;k<=3;k++)
				for(l=1;l<=3;l++)
					if(b[a[i*3-3+k][j*3-3+l]]==0)
						b[a[i*3-3+k][j*3-3+l]]=1;
					else{
						cout<<"No";
						return 0;
					}
		} 
	cout<<"Yes";
	return 0;
}
