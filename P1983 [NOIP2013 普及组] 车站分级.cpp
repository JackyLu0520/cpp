#include<bits/stdc++.h>
using namespace std;
const int MAXN=1001;
struct Node{
	int u,level;
	Node(int _u,int _level){
		u=_u;
		level=_level;
	}
};
int n,m,ans,in[MAXN],s[MAXN];
vector<int> adj[MAXN];
bool stoped[MAXN],visited[MAXN][MAXN];
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		memset(stoped,0,sizeof(stoped));
		int t;
		cin>>t;
		for(int j=1;j<=t;j++){
			cin>>s[j];
			stoped[s[j]]=1;
		}
		for(int u=s[1];u<=s[t];u++){
			if(stoped[u])	continue;
			for(int j=1;j<=t;j++){
				int v=s[j];
				if(visited[u][v])	continue;
				adj[u].push_back(v);
				in[v]++;
				visited[u][v]=1;
			}
		}
	}
	queue<Node> q;
	for(int i=1;i<=n;i++)
		if(!in[i])
			q.push(Node(i,1));
	while(!q.empty()){
		Node cur=q.front();
		q.pop();
		for(int i=0;i<adj[cur.u].size();i++){
			int v=adj[cur.u][i];
			in[v]--;
			if(!in[v]){
				q.push(Node(v,cur.level+1));
				ans=max(ans,cur.level+1);
			}
		}
	}
	cout<<ans;
	return 0;
} 
