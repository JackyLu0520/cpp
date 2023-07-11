#include<iostream>
using namespace std;
int a(int m)
{
	if(m==1)
	    return 0;
	else if(m==2)
		return 1;
	else
		return (m-1)*(a(m-1)+a(m-2)); 
}
int main()
{
	int n;
	cin>>n; 
	cout<<a(n);
	return 0;		
}
