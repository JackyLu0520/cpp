#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int i,a1,a2,a3;
	a1=a2=1;
	cout<<setw(10)<<a1<<setw(10)<<a2;
	for(i=3;i<=40;i++)
	{
		a3=a1+a2;
		cout<<setw(10)<<a3;
		a1=a2;
		a2=a3;
	} 
	return 0;
} 
