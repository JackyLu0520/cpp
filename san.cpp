#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int i,j;
	for(i=1;i<=5;i++)
	{
		cout<<setw(6-i);
		for(j=1;j<=i*2-1;j++)
			cout<<"*";
		cout<<endl;
	}
} 
