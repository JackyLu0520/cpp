#include<iostream>
using namespace std;
bool isPrime(int n)
{
	int i;
	if(n==1)
		return false;
	for(i=2;i*i<=n;i+=1)
		if(n%i==0)
			return false;
	return true; 
}
int main(){
	int i,j=0;
	cout<<"int p[]={";
	for(i=1;i<=50000;i++)
		if(isPrime(i)){
			cout<<i<<',';
			j++;
		}
	cout<<"\b};\n"<<j;
	return 0;
} 
