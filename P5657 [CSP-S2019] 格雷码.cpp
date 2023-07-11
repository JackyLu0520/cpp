#include<bits/stdc++.h>
using namespace std;
int main(){
	unsigned long long n,k,g;
	cin>>n>>k;
	g=k^(k>>1);
	for(int i=n-1;i>=0;i--)
		cout<<((g&(1<<i))?1:0);
	return 0;
}