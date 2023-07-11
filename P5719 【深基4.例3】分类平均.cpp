#include<bits/stdc++.h>
using namespace std;
int n,k,sy,sn;
float ay,an;
int main(){
	int i;
	cin>>n>>k;
	for(i=1;i<=n;i++)
		if(i%k==0)
			sy+=i;
		else
			sn+=i;
	ay=sy*1.0/(n/k);
	an=sn*1.0/(n-n/k);
	cout<<fixed<<setprecision(1)<<ay<<' '<<fixed<<setprecision(1)<<an;
	return 0;
}
