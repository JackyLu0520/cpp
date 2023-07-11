#include<bits/stdc++.h>
using namespace std;
struct E{
	int u,v,w;
	bool operator < (const E &a) const{
		return w<a.w;
	}
}e[200010];
int n,m,fa[5010],ans=0,cnt=0;
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
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
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
	if(cnt!=n-1)	cout<<"orz";
	else			cout<<ans;
	return 0;
}