#include<iostream>
using namespace std;
int main()
{
	int i,n,t,bucket[11]={0};
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>t;
		bucket[t]++;
	}
	for(i=0;i<11;i++)
		while(bucket[i])
		{
			cout<<i<<' ';
			bucket[i]--; 
		}
    return 0;
}
