#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<unordered_set<string>> a(n+1);
	for(int i=1;i<=n;i++){
		int l;
		cin>>l;
		for(int j=1;j<=l;j++){
			string word;
			cin>>word;
			a[i].insert(word);
		}
	}
	int m;
	cin>>m;
	while(m--){
		string word;
		cin>>word;
		for(int i=1;i<=n;i++)
			if(a[i].count(word))	cout<<i<<' ';
		cout<<endl;
	}
	return 0;
}