#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int i;
	char a;
	for(i=1;i<=4;i++)
	{
		if((i!=1)+(i==3)+(i==4)+(i!=4)==3)
		{
			a=i+64;
			cout<<a;
			break;
		}
	} 
	return 0;
} 
