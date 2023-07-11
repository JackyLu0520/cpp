#include<iostream>
#include<cstdio>
#include<cmath>
#pragma GCC optimize(2)
using namespace std;
int main()
{
	long long a,s1=0,s2=0;
	while((scanf("%d",&a))!=EOF)
	{
		s1++;
		s2+=a;
	}
	cout<<((long long)(pow(2,s1-1))*s2);
}
