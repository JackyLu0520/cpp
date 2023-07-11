#include<iostream>
using namespace std;
int main()
{
	int a;
	do
	{
	    cin>>a;      	
	} 
	while(a<0 || a>100);
	cout<<a;
	return 0;
}
