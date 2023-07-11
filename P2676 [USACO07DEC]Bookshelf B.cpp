#include<bits/stdc++.h>
using namespace std;
int n,h[20010],s=0,b;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int i;
	cin>>n>>b;
	for(i=0;i<n;i++)
		cin>>h[i];
	sort(h,h+n,cmp);
	for(i=0;s<b;i++)
		s+=h[i];
	cout<<i;
	return 0;
}
