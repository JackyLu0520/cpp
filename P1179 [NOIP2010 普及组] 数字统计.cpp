#include<bits/stdc++.h>
using namespace std;
int l,r;
int count(int n){
	int cnt=0;
	while(n){
		cnt+=(n%10==2);
		n/=10;
	}
	return cnt;
}
int main(){
	int cnt=0;
	cin>>l>>r;
	for(int i=l;i<=r;i++)
		cnt+=count(i);
	cout<<cnt;
	return 0;
}