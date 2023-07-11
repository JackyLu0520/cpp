#include<bits/stdc++.h>
using namespace std;
long long n,ans;
int main(){
	int i;
	cin>>n;
	while(n){
		n&=n-1;
		ans++; 
	}
	cout<<ans;
	return 0;
} 
