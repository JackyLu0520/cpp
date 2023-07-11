#include<iostream>
#pragma GCC optimize(3)
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
	int i;
	for(i=2;i<2000000000;i++)
		if(isPrime(i))
			cout<<i<<' ';
	return 0;
}
