#include<iostream>
#include<string>
using namespace std;
int main(){
	string n,m;
	int i;
	cin>>n;
	for(i=n.size()-1;i>=0;i--)
		m+=n[i]; 
	cout<<m;
	return 0;
}
