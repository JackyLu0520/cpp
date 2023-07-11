#include<bits/stdc++.h>
using namespace std;
int n,a[100010],s[100010]={0},Max=-2147483648;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]*a[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			Max=max(Max,s[j]/s[i-1]);
	cout<<Max;
	return 0;
}