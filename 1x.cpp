#include<iostream>
using namespace std;
int main()
{
	int i,j,sum,n,a;
	cout<<"n:";
	cin>>n;
	sum=0;
	a=1;
	for(i=1;i<=n;i++)
	{
	    for(j=1;j<=4;j++)
	    {
	    	a*=i;			 
		}
		sum+=a;
		a=1; 
    }
    cout<<"1x1x1x1+2x2x2x2+..."<<n<<"x"<<n<<"x"<<n<<"x"<<n<<"="<<sum;
    return 0;
}
