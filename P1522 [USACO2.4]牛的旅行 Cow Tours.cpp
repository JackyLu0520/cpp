#include<bits/stdc++.h>
using namespace std;
const int MAXN=151,INF=0x3f3f3f3f;
struct Node{
	int x,y;
}node[MAXN];
double getDis(int i,int j){
	int dx=node[i].x-node[j].x;
	int dy=node[i].y-node[j].y;
	return sqrt(dx*dx+dy*dy);
}
int n;
double rad1,rad2=INF,dis[MAXN][MAXN],f[MAXN];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>node[i].x>>node[i].y;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			char c=getchar();
			if(c!='0')	dis[i][j]=getDis(i,j);
			else if(i!=j)	dis[i][j]=INF;
		}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(dis[i][k]!=INF&&dis[k][j]!=INF&&dis[i][k]+dis[k][j]<dis[i][j])
					dis[i][j]=dis[i][k]+dis[k][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(dis[i][j]!=INF)	f[i]=max(f[i],dis[i][j]);
			
		}
}
