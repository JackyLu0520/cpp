#include<iostream>
using namespace std;
int s=0,i,a=0;
int main()
{
	for(i=0;i<8;i++)
	{
		a=a*10+8;
		s+=a;
	}
	cout<<s;	
	return 0;
}
