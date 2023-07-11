#include<bits/stdc++.h>
using namespace std;
int main(){
	string s,t,ans="abcdefghijklmnopqrstuvwxyz";
	int i;
	cin>>s>>t;
	for(i=0;i<min(s.size(),t.size());i++)
		if(s[i]!=t[i])
			break;
	if(s[i]<t[i]){
		swap(ans[s[i]-'a'],ans[t[i]-'a']);
		cout<<ans;
	}
	else
		cout<<ans;
	return 0;
}
