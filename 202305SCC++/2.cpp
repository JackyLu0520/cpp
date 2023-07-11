#include<bits/stdc++.h>
using namespace std;
int pow4(int n){
	return n*n*n*n;
}
int main(){
	int n,m;
	cin>>n>>m;
	if(n<1000)	n=1000;
	if(m>9999)	m=9999;
	for(int i=n;i<=m;i++)
		if(pow4(i/1000%10)+
			pow4(i/100%10)+
			pow4(i/10%10)+
			pow4(i/1%10)==i)
			cout<<i<<' ';
	return 0;
}
