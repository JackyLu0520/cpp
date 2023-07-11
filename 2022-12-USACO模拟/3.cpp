#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int Max=0;
		cin>>a[i]>>b[i];
		sort(a,a+i+1);
		sort(b,b+i+1,greater<int>());
		for(int j=0;j<=i;j++){
			Max=max(Max,a[j]+b[j]);
		}
		cout<<Max<<endl;
	}
	return 0;
}