#include<iostream>
using namespace std;
int main()
{
	int s=0,n;
	cin>>n;
	for(int i=1;i<=n;i++)
		if(!(i/1%10==7||i/10%10==7||i%7==0))
			s+=i*i;
	cout<<s;
	return 0;
}
