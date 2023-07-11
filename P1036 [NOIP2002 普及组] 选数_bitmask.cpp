#include<bits/stdc++.h>
using namespace std;
int n,k,x[25],cnt,s=0,num=0;
bool isPrime(int a){
	int i;
	if(a==1)	return 0;
	for(i=2;i*i<=a;i++)
		if(a%i==0)
			return 0;
	return 1;
}
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>x[i];
	for(int mask=0;mask<(1<<n);mask++){
		s=0,num=0;
		for(int i=0;i<n;i++)
			if(mask&(1<<i)){
				s+=x[i];
				num++;
			}
		if(isPrime(s)&&num==k)	cnt++;
	}
	cout<<cnt;
	return 0;
}
