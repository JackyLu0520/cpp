#include<bits/stdc++.h>
using namespace std;
bool check(int x){
	if(x%7==0)	return 1;
	int t=x;
	while(t){
		if(t%10==7)	return 1;
		t/=10;
	}
	return 0;
}
int main(){
	int m,n,cnt=0;
	cin>>m>>n;
	for(int i=m;i<=n;i++)
		if(check(i))
			cnt++;
	cout<<cnt;
	return 0;
}