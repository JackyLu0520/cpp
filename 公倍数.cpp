#include<iostream>
using namespace std;
int main()
{
	int s=0,x=0,y=0,t=0,i=0;
	cin>>x>>y;
	if(x>y)
	{
		t=x;
		x=y;
		y=t;
	}
	i=1;
	s=y*i;
	while(s%x!=0)
	{
	    i++;
		s=y*i;	
	}
	cout<<s;
	return 0;
}
