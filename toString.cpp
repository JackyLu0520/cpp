#include<bits/stdc++.h>
using namespace std;
string toString(int n){
	string s="";
	while(n){
		s+=n%10+'0';
		n/=10;
	}
	reverse(s.begin(),s.end());
	return s;
}
int main(){
	int num;
	cin>>num;
	cout<<"toString(num)="<<toString(num);
	return 0;
}
