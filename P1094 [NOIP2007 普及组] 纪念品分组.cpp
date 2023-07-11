#include<bits/stdc++.h>
using namespace std;
int w,n,p[30010],cnt=0;
int main(){
	cin>>w>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	sort(p+1,p+n+1);
	int l=1,r=n;
	while(l<=r){
		while(p[l]+p[r]>w){
			r--;
			cnt++;
		}
		cnt++;
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
}