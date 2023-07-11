#include<iostream>
using namespace std;
int main()
{
	int n,t,a,b[10000];
	cin>>n>>t;
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
		if(b[i]<=t)
			a++;
	}
	cout<<a;
} 
