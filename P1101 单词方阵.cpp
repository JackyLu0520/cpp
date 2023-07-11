#include<bits/stdc++.h>
using namespace std;
string word="yizhong";
char a[100][100],b[100][100];
int n,offset[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,-1},{-1,1}};
bool f=1;
int main(){
	int i,j,k,l,x,y;
	memset(b,'*',sizeof(b));
	cin>>n;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>a[i][j];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			for(k=0;k<8;k++){
				x=i,y=j;
				f=1;
				for(l=0;l<7;l++){
					if(a[x][y]!=word[l])
						f=0;
					x+=offset[k][0];
					y+=offset[k][1];
				}
				x=i,y=j;
				if(f==1)
					for(l=0;l<7;l++){
						b[x][y]=word[l];
						x+=offset[k][0];
						y+=offset[k][1];
					}
			}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			cout<<b[i][j];
		cout<<endl;
	}
	return 0;
}
