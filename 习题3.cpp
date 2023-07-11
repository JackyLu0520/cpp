#include<iostream>
using namespace std;
int main()
{
	float a=0,b=0,c=0,d=0;
	while(1)
	{
		cin>>a;
		if(a==-1)
		    break;
		else
		{
			b+=a;
			c++;
		}
	}
	d=b/c;
	cout<<d;
	return 0;
}
