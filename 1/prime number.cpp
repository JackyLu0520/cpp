#include<iostream>
using namespace std;
int main()
{
	int x,i;
	bool f=true;
	cin>>x;
	for(i=2;i<x;i++)
		if(x%i==0)
		{
			f=false;
			break;	
		}
	if(x==1)
		f=false;
	if(f)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}
