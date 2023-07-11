#include<iostream> 
using namespace std;
int main()
{
	int time=0,c=1,t=0,n=0,g1=0;
	bool f;
	do
	{
		f=0;
		time++;
		if(t<9)
		{
			f=true;
			t++;
		}
		if(n<9&&time%2==0)
		{
			f=true;
			n++;
		}
		if(g1<9&&time%4==0)
		{
			f=true;
			g1++;
		}
		if(f)	c++;
	}while(t+n+g1<9*3); 
	cout<<c;
	return 0;
}
