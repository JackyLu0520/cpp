#include<bits/stdc++.h>
using namespace std;
int x,y,p,cnt=0;
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main(){
	cin>>x>>y;
	if(y%x!=0){cout<<0;return 0;}
	for(int p=1;p<=y/x;p++)
		if((y/x)%p==0&&gcd(p,y/x/p)==1)
			cnt++;
	cout<<cnt;
	return 0;
}