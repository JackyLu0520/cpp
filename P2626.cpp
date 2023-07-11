#include<iostream>
using namespace std;
bool isPrime(int n)
{
	int i;
	if(n==1)
		return false;
	if(n==2)
		return true;
	for(i=2;i*i<=n;i++)
		if(n%i==0)
			return false;
	return true;
}
int main(){
	int fibo[49],n,i;
	cin>>n;
	fibo[1]=fibo[2]=1;
	for(i=3;i<=n;i++)
		fibo[i]=fibo[i-1]+fibo[i-2];
	for
}
