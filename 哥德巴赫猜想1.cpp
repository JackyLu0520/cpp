#include<iostream>
using namespace std;
bool prime(int x)
{
	if(x==1)	return false;
	if(x==2)	return true;	
	for(int i=2;i<x;i++)
		if(x%i==0)
			return false;
	return true;
} 
int main()
{
	int i,j,n;
	cin>>n; 
	for(i=4;i<=10000;i+=2)
	{
		for(j=2;j<i;j++)
			if(prime(j))
				if(prime(i-j))
				{
					cout<<i<<'='<<j<<'+'<<i-j<<endl;
					break;
				}
		if(i==j)	cout<<"¡Á"<<endl;
	}
}
