#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
ull binpow(ull a,ull p){
	long long ans=1;
	while(p){
		if(p&1)	ans*=a;
		a*=a;
		p>>=1;
	}
	return ans;
}
int main(){
	ull a,p;
	cin>>a>>p;
	cout<<binpow(a,p);
	return 0;
}
