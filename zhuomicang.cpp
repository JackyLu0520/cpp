#include<iostream>
using namespace std;
int main()
{
	int i,j;
	bool a[11]={false,false,false,false,false,false,false,false,false,false,true};
	i=10;
	j=10;
	for(i=1;i<=1000;i++)
	{
		j=(j+i)%10;
		if(j==0)
			j=10;
		a[j]=true;	
	}
	for(j=1;j<=10;j++)
		if(!(a[j]))	cout<<j<<' ';
	return 0;
} 
