#include<iostream>
using namespace std;
int main()
{
	long long N,i;
	cin>>N;
	for(i=1;i*i<=N;i++)
		cout<<i*i<<' ';
	return 0;	
}
