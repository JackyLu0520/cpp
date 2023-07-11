#include<bits/stdc++.h>
using namespace std;
int r,x;
int count(int n){
	int cnt=0;
	while(n){
		cnt+=(n%10==x);
		n/=10;
	}
	return cnt;
}
int main(){
	int cnt=0;
	cin>>r>>x;
	for(int i=1;i<=r;i++)
		cnt+=count(i);
	cout<<cnt;
	return 0;
}