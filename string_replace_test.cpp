#include<bits/stdc++.h>
using namespace std;
int main(){
	string s="abcdefiiilll",s1="gh",s2="jk";
	cout<<s.replace(6,2,s1)<<endl;
	cout<<s.replace(s.end()-3,s.end()-1,s2)<<endl;
	return 0;
}
