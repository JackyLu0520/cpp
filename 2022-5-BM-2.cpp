#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	cin>>t;
	while(t--){
		string s;
		bool r=0,g=0,b=0;
		int i;
		cin>>s;
		for(i=0;i<s.size();i++)
			if(s[i]=='r')	r=1;
			else if(s[i]=='g')	g=1;
			else if(s[i]=='b')	b=1;
			else if(s[i]=='R')	if(!r){cout<<"NO"<<endl;break;}else;
			else if(s[i]=='G')	if(!g){cout<<"NO"<<endl;break;}else;
			else if(s[i]=='B')	if(!b){cout<<"NO"<<endl;break;}else;
		if(i==s.size())	cout<<"YES"<<endl;
	}
	return 0;
}