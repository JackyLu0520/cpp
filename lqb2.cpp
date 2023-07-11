#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)
		cout<<'*';
	for(i=n-1;i>0;i--)
		cout<<endl<<setw(i)<<'*';
	for(i=0;i<n;i++)
		cout<<'*';
	return 0;
}
