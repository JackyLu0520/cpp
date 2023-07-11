#include<bits/stdc++.h>
using namespace std;
struct P{
	int p,c;
}a[1000010];
int n,k,w;
bool cmp(P a,P b){
	return a.c<b.c;
}
int main(){
	cin>>n>>k>>w;
	for(int i=1;i<=n;i++)	cin>>a[i].p;
	for(int i=1;i<=n;i++)	cin>>a[i].c;
	sort(a+1,a+n+1,cmp);
	priority_queue<int> q;
	int cur=1;
	for(int i=1;i<=k;i++){
		while(cur<=n&&a[cur].c<=w){
			q.push(a[cur].p);
			cur++;
		}
		if(q.size()){
			w+=q.top();
			q.pop();
		}else{
			break;
		}
	}
	cout<<w;
	return 0;
}