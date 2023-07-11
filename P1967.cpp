#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=1e4,inf=0x3f3f3f3f;
int n,m,depth[MAXN+10],q,vis[MAXN+10];
//图的边
struct E1{
	int u,v,w;
	E1(){}
	E1(int U,int V,int W){
		u=U;
		v=V;
		w=W;
	}
};
vector<E1> Edges;
//最大生成树,w为最大载重
struct E2{
	int v,w;
	E2(){}
	E2(int V,int W){
		v=V;
		w=W;
	}
};
vector<E2> adj[MAXN+10];
int fa[MAXN+10][25],w[MAXN+10][25];
//并查集
int fa1[MAXN+10];
void make_set(){
	for(int i=1;i<=n;i++)	fa1[i]=i;
}
int query(int x){
	return fa1[x]==x?x:query(fa1[x]);
}
void merge(int x,int y){
	fa1[query(x)]=query(y);
}
//Kruskal求最大生成树
bool cmp(E1 a,E1 b){
	return a.w>b.w;
}
void Kruskal(){
	sort(Edges.begin(),Edges.end(),cmp);
	make_set();
	for(auto e:Edges)
		if(query(e.u)!=query(e.v)){
			merge(e.u,e.v);
			adj[e.u].push_back(E2(e.v,e.w));
			adj[e.v].push_back(E2(e.u,e.w));
		}
}
//lca
void dfs(int u,int pre){
	for(int i=1;i<=20;i++){
		fa[u][i]=fa[fa[u][i-1]][i-1];
		w[u][i]=min(w[u][i-1],w[fa[u][i-1]][i-1]);
	}
	for(auto e:adj[u])
		if(e.v!=pre){
			vis[e.v]=1;
			fa[e.v][0]=u;
			w[e.v][0]=e.w;
			depth[e.v]=depth[u]+1;
			dfs(e.v,u);
		}
}
int lca(int u,int v){
	if(depth[u]<depth[v])	swap(u,v);
	int diff=depth[u]-depth[v];
	for(int i=0;diff;i++){
		if(diff&1)	u=fa[u][i];
		diff>>=1;
	}
	if(u==v)	return u;
	for(int i=20;i>=0;i--)
		if(fa[u][i]!=fa[v][i]){
			u=fa[u][i];
			v=fa[v][i];
		}
	return fa[u][0];
}
//main
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d",&u,&v,&w);
		Edges.push_back(E1(u,v,w));
	}
	Kruskal();
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			vis[i]=1;
			fa[i][0]=0;
			w[i][0]=inf;
			depth[i]=1;
			dfs(i,0);
		}
	scanf("%d",&q);
	for(int i=1;i<q;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		printf("%d\n",lca(u,v));
	}
	return 0;
}