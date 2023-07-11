#include<bits/stdc++.h>
using namespace std;
int n;
bool f=1;
int main(){
	cin>>n;
	if(n==0){
		cout<<0;
		return 0;
	}
	if(n<0){
		cout<<'-';
		n=-n;
	}
	while(n%10==0){
		n/=10;
	}
	while(n){
		cout<<n%10;
		n/=10;
	}
	return 0;
} 
