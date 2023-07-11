#include<bits/stdc++.h>
using namespace std;
int n,m,Max=0;
bool a[110][110];
int offset[4][2]={{1,1},{-1,1},{-1,-1},{1,-1}};
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=0;k<4;k++){
				int x=i,y=j,cnt,cnt1=0;
				for(cnt=0;a[x][y];cnt++)
					x+=offset[k][0],y+=offset[k][1];
				x-=offset[k][0],y-=offset[k][1];
				for(int p=min(i,x);p<=max(i,x);p++)
					for(int q=min(j,y);q<=max(j,y);q++)
						cnt1+=a[p][q];
				if(cnt==cnt1)	Max=max(Max,cnt);
			}
	cout<<Max;
	return 0;
}