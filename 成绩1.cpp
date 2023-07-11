#include<iostream>
using namespace std;
int main()
{
	int a[5],n,b;
	cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4];
	b=a[0];
	for(n=0;n<=4;n++)
	{
		if(b>a[n])
			b=a[n];		 
	}
	cout<<b;
    return 0;
}
