#include<bits/stdc++.h>
using namespace std;
int n;
string solve(int n){
	string s;
	if(n==0||n==1||n==2){
		s+=char(n+'0');
		return s;
	}
	int t=n,i;
	for(i=0;t;i++){
		t>>=1;
	}
	for(;i>=0;i--){
		if(n&(1<<i)){
			if(i!=1)
				s+="2("+solve(i)+")";
			else
				s+="2";
			if((1<<i)!=(n&(-n)))	s+="+";
		}
	}
	return s;
}
int main(){
	cin>>n;
	cout<<solve(n);
	return 0;
}