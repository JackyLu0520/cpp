#include<bits/stdc++.h>
using namespace std;
int t,n,a[110],b[110];
int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		int max1=0,max2=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			cin>>b[i];
		for(int i=1;i<=n;i++){
			max1=max(max1,max(a[i],b[i]));
			max2=max(max2,min(a[i],b[i]));
		}
		cout<<max1*max2<<endl;
	}
	return 0;
}