#include<iostream>
using namespace std;
int main()
{
	int x,y,i,t;
	cin>>x>>y;
	if(x<y)
	{
	    t=x;
		x=y;
		y=t;	
	}
	i=y;
	while(x%i!=0||y%i!=0)
	{
	    i--;	
	}
	cout<<i;
	return 0;
}
