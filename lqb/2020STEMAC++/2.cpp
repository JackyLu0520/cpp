#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int cnt=0;
	getline(cin,s);
	for(int i=0;i<s.size();i++)
		if(s[i]=='.')
			cnt++;
	cout<<s.size()<<endl<<cnt;
	return 0;
}
