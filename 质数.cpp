#include<iostream>
using namespace std;
int main()
{ 
	bool a[101];
	int i,j,b=0;
	for(i=2;i<100;i++)
		a[i]=true;
	a[0]=a[1]=false;
	i=1;
	do
	{
		i++;
		if(a[i])
			for(j=2;j<=100/i;j++)
				a[i*j]=false;
	}while(i<100);
	for(i=0;i<100;i++)
		if(a[i])
		{
			cout<<i<<' ';
			b++;
		}
	cout<<endl;
	cout<<b;
	return 0;
}
