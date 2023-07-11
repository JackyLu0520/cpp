#include<iostream>
using namespace std;
int fun(int a)
{
	int num=0;
	for(int i=1;i<=a;i++)
		if(a%i==0) num++;
		return num;
}
int main()
{
	int i;
	for(i=1;i<=100;i++)
		if(fun(i)==3)
			cout<<i<<" ";	
	return 0;	
}
