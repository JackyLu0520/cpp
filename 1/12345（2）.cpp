#include<iostream>
using namespace std;
int i,s=1;
int main()
{
	for(i=1;i<=123456789;i=i*10+i%10+1)
		s+=i;
	cout<<s;
	return 0;
}
