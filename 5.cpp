#include<iostream>
using namespace std;
int main()
{
	int n,a[100],num=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		for(int j=1;j<=a[i];j++)
		{
			if(a[i]==j*j)
				num++;
		}
	}
	cout<<num;
	return 0;		
}
