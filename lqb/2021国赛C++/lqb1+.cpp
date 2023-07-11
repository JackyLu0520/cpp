#include <iostream>
#include <string>
using namespace std;
int main(){
	string s;
	int l,i;
	getline(cin,s);
	l=s.size();
	for(i=0;i<l;i++)
		if(s[i]>='A'&&s[i]<='Z'||s[i]>='a'&&s[i]<='z'){
			s[i]=s[i]+3;
			if(s[i]<'a'&&s[i]>'Z'||s[i]>'z')
				s[i]-=26;
		}
	cout<<s;
	return 0;
}  
