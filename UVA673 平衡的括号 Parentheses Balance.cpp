#include<bits/stdc++.h>
using namespace std;
stack<char> stks[100000];
string s[100000];
int n;
int main(){
	int i,j;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>s[i];
		stks[i].push('#');
		for(j=0;j<s[i].size();j++)
			if(s[i][j]==')'&&stks[i].top()=='('||
				s[i][j]==']'&&stks[i].top()=='[')
				stks[i].pop();
			else
				stks[i].push(s[i][j]);
		if(stks[i].top()=='#')
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
