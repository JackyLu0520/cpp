#include<iostream>
using namespace std;
int main()
{
	long long a,sum;
	int i;
	a=1;
	sum=0;
	for(i=1;i<=64;i++)
	{
      a*=2;
      sum+=a;
      cout<<i<<" "<<a<<endl;
    }
    cout<<sum;
    return 0;
} 
