#include<bits/stdc++.h>
using namespace std;
int fun(int n){
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(n%i==0)
			 cnt++;
	return cnt;
}
int main(){
	int n,i;
	cin>>n;
	for(i=1;fun(i)!=n;i++)	;
	cout<<i;
	return 0;
}
