#include<iostream>
using namespace std;
int i,a=1,s=1;
int main()
{
	for(i=2;i<=9;i++)
	{
		a=a*10+i;
		s+=a;
	}
	cout<<s;
	return 0;
}
