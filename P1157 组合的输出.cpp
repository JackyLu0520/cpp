#include<bits/stdc++.h>
using namespace std;
int n,r;
vector<int> a;
void DFS(int step){
	int i; 
	if(a.size()==r||step>n){
		if(a.size()==r){
			for(i=0;i<r;i++)	cout<<setw(3)<<a[i];
			cout<<endl;
		}
		return;
	}
	a.push_back(step);
	DFS(step+1);
	a.pop_back();
	DFS(step+1);
}
int main(){
	cin>>n>>r;
	DFS(1);
	return 0;
}
