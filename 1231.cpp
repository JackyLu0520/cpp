#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d,e,f,g,i;
	cin>>a>>b>>c>>d;
	i=0;
	while(1)
	{
		i++;
		if(i%a==0&&i%b==0)
		{
			break;
		}		
	}
	e=i;
	i=0;
	while(1)
	{
		i++;
		if(i%c==0&&i%d==0)
		{
			break;
		}		
	} 
	f=i;
	cout<<e<<" "<<f<<endl;
	i=e;
	while(1)
	{
		i--;
		if(e%i==0&&f%i==0)
		{
			break;
		}		
	}
	g=i;
	cout<<g;
} 
