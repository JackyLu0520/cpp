#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("title.in","r",stdin);
	freopen("title.out","w",stdout);
	string s;
	int c=0;
	getline(cin,s);
	for(int i=0;i<s.size();i++)
		if(s[i]!=' ')
			c++;
	cout<<c;
	return 0;
}
