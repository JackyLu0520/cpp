#include<iostream>
#include<string>
using namespace std;
string s="Today, I ate ",s1=" apple";
int main(){
	int a;
	cin>>a;
	cout<<s<<a<<s1<<(a>1?"s.":".");
	return 0;
}
