#include<bits/stdc++.h>
using namespace std;
int n,a[100010],cnt=0;
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<2*n;i++)
		cin>>a[i];
	for(int i=0;i<2*n-1;i+=2)
		if(a[i]/2!=a[i+1]/2){
			for(int j=i+2;j<2*n;j++)
				if(a[i]/2==a[j]/2){
					swap(a[i+1],a[j]);
					cnt++;
					break;
				}
		}
	cout<<cnt;
	return 0;
}