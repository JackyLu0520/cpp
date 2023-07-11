#include<iostream>
using namespace std;
bool isPrime(int m){
	int i;
	if(m<2)
		return 0;
	for(i=2;i*i<=m;i++)
		if(m%i==0)
			return 0;
	return 1;
}
int main(){
	int n,i;
	cin>>n;
	for(i=n/2;!(isPrime(i)&&isPrime(n-i));i--)	;
	cout<<n-i-i;
	return 0;
} 
