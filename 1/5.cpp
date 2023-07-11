#include<iostream>
using namespace std;
int s=0,i;
int main()
{
	for(i=8;i<=88888888;i=i*10+8)	s+=i;
	cout<<s;	
	return 0;
}
