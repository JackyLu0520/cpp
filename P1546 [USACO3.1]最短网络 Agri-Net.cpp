#include<bits/stdc++.h>
using namespace std;
struct E{
	int u,v,w;
	E(){}
	E(int U,int V,int W){u=U;v=V;w=W;}
	bool operator < (const E &a) const{
		return w<a.w;
	}
}e[10000];
int n,m,fa[110],ans=0,cnt=0,cur=1;
int Find(int x){
	return fa[x]==x?x:Find(fa[x]);
}
bool Union(int x,int y){
	int fx=Find(x),fy=Find(y);
	if(fx==fy)	return 0;
	fa[fx]=fy;
	return 1;
}
int main(){
	cin>>n;
	m=n*n-n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			if(i!=j)
				e[cur++]=E(i,j,w);
		}
	for(int i=1;i<=n;i++)
		fa[i]=i;
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++){
		if(Union(e[i].u,e[i].v)){
			ans+=e[i].w;
			cnt++;
		}
		if(cnt==n-1)	break;
	}
	cout<<ans;
	return 0;
}