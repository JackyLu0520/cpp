#include<iostream>
using namespace std;
int main()
{
	bool a[97];
	int i,j,sum=0;
	for(i=1;i<=97;i++)
	{
		a[i]=true;
	}
	for(i=2;i<=42;i++)
	{
		for(j=i;j<=96;j=j+i)
			a[j]=!a[j];		 
	}
	for(i=1;i<=96;i++)
	{
		if(a[i])
		{
			cout<<i<<" ";
			sum++;
		}
    }
    cout<<endl<<sum; 
    return 0;
}
