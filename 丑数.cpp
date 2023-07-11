#include<iostream>
using namespace std;
bool fun(int a)
{
	int b;
	b=a;
	while(b%2==0||b%3==0||b%5==0)
	{
		if(b%2==0)
			b/=2; 
		if(b%3==0)
			b/=3;
		if(b%5==0)
			b/=5;
	} 
	return b==1;
}
int main()
{
	int i;
	for(i=1;i<=100;i++)
		if(fun(i))
			cout<<i<<' ';
	return 0;
}
