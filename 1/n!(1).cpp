#include<iostream>
using namespace std;
int i,s=1,s1=1,j;
int main()
{
	for(i=1;i<=11;i+=2)
	{
		for(j=1;j<=i;j++)	s1*=j;
		s+=s1;
	}
	cout<<s;
	return 0;
}
