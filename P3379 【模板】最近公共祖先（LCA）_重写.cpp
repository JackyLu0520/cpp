#include<bits/stdc++.h>
using namespace std;
int n, m, s,depth[500010];
vector<int> adj[500010];
int fa[500010][21];
void dfs(int u,int pre) {
	fa[u][0] = pre;
	for (int i = 1; i <= 20; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = 0; i < adj[u].size(); i++) 
		if (adj[u][i] != pre) {
			depth[adj[u][i]] = depth[u] + 1;
			dfs(adj[u][i], u);
		}
}
int lca(int x, int y) {
	if (depth[x] < depth[y])	swap(x, y);
	int diff = depth[x] - depth[y];
	for (int i = 0; diff; i++) {
		if (diff & 1)	x = fa[x][i];
		diff >>= 1;
	}
	if(x==y)	return x;
	for(int i=20;i>=0;i--)
		if (fa[x][i] != fa[y][i]) {
			x = fa[x][i];
			y = fa[y][i];
		}
	return fa[x][0];
}
int main() {
	cin >> n >> m >> s;
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(s, 0);
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << endl;
	}
	return 0;
}