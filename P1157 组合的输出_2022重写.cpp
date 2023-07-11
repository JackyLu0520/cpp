#include<bits/stdc++.h>
using namespace std;
int n,r;
vector<int> a;
void dfs(int s){
	if(a.size()==r){
		for(int x:a){
			cout<<setw(3)<<x;
		}
		cout<<endl;
		return;
	}
	if(s>n)	return;
	a.push_back(s);
	dfs(s+1);
	a.pop_back();
	dfs(s+1);
}
int main(){
	cin>>n>>r;
	dfs(1);
	return 0;
}