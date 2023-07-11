#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	s.insert(0,"$");
	for(int i=1;i<=s.size();i+=2)
		s.insert(i,"#");
	cout<<s;
	return 0;
} 
