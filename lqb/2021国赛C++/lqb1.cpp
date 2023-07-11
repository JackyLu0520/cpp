#include <iostream>
#include <string>
using namespace std;
int main(){
	string s;
	int l,i;
	getline(cin,s);
	l=s.size();
	for(i=0;i<l;i++)
		s[i]=s[i]+3;
	cout<<s;
	return 0;
}  
