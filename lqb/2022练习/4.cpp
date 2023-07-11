#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a[70]={0,1,2};
	int n;
	cin>>n;
	for(int i=3;i<=n;i++){
		a[i]=a[i-1]+a[i-2];
	}
	cout<<a[n];
	return 0;
}
