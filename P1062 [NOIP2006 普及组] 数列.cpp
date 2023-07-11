#include<bits/stdc++.h>
using namespace std;
int main(){
	long long k,n,s=0,p=1;
	cin>>k>>n;
	for(int i=0;n;i++){
		if(n&1)	s+=p;
		n>>=1;
		p*=k;
	}
	cout<<s;
	return 0;
}