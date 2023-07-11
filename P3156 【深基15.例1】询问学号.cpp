#include<bits/stdc++.h>
using namespace std;
int n,m,t;
vector<int> s;
int main(){
	int i;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>t;
		s.push_back(t);
	}
	for(i=0;i<m;i++){
		cin>>t;
		cout<<s[t-1]<<endl;
	}
	return 0;
}
