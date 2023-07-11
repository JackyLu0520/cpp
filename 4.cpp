#include<iostream>
using namespace std;
int main()
{
	long long a;
	cin>>a;
	while(a>0)
	{
		cout<<a%10;
		a/=10;
	}
	return 0;		
}
