#include<iostream>
using namespace std;
int main()
{
	int i=0,sum=0;
	while(i<=180)
	{
		sum+=i;
		i+=6;
	}
	cout<<"6+12+18+24+...+180="<<sum;
	return 0;
}
