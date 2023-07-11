#include<iostream>
using namespace std;
int i,s=0,s1=1,j;
int main()
{
	for(i=1;i<=10;i++)
	{
		s1*=i;
		s+=s1;
	}
	cout<<s;
	return 0;
}
