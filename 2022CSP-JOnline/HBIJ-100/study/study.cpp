#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("study.in","r",stdin);
	freopen("study.out","w",stdout);
	string s;
	getline(cin,s);
	while(s[0]==' ')	s.erase(s.begin());
	while(s[s.size()-1]==' ')	s.erase(s.end()-1);
	for(int i=0;i<s.size();i++){
		if(i==0||s[i-1]==' ')
			if(s[i]>='a'&&s[i]<='z')
				s[i]-=32;
			else;
		else if(s[i]>='A'&&s[i]<='Z')
			s[i]+=32;
	}
	cout<<s;
	return 0;
}