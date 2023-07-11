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
	int n,i;
	cin>>n;
	for(i=n/2;i>2;i++)
		if(n%i==0)
			if(isPrime(i)){
				cout<<i;
				break;
			}
	return 0;
}
