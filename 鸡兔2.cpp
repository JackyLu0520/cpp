#include<iostream>
using namespace std;
int main()
{
	int i,j;
	for(i=1;i<=35-1;i++)
		for(j=1;j<=94/4;j++)
			if(i+j==35&&i*2+j*4==94)
			cout<<i<<" "<<j;
} 
