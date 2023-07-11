#include<iostream>
using namespace std;
bool isprime(int n)
{
	int i;
	if(n!=2&&n%2==0||n==1)
		return false;
	for(i=2;i*i<=n;i++)
		if(n%i==0)
			return false;
	return true;
}
int main()
{
	int l,i,s=0,n=0;
	cin>>l;
	for(i=2;;i++)
		if(isprime(i))
		{
			s+=i;
			if(s<=l)
			{
				cout<<i<<endl;
				n++;
			}
			else
				break;
		}
	cout<<n;
}
