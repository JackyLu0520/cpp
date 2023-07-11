#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
	int x,y,s,a,n,sum=0;
	srand(time(0));
	for(int i=1;i<=10;i++)
	{
		x=rand()%9+1; 
		y=rand()%9+1;
		s=rand()%2;
		if(x<y&&s==1)
		{
			x=y-x;
			y=y-x;
			x=x+y;	 
		} 
		switch(s)
		{
			case 0:
				a=x+y;
				cout<<x<<"+"<<y<<"=";
				break;
			case 1:
				a=x-y;
				cout<<x<<"-"<<y<<"=";
				break;	
		}
		cin>>n;
		if(n==a)
		{
			sum+=10;
			cout<<"¶Ô"<<endl; 
		}
		else
			cout<<"´í"<<endl;
	}
	cout<<sum; 
	return 0;
}
