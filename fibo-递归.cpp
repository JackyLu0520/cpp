#include<iostream>
using namespace std;
long long fibo(int n)
{
	return n==1||n==2?1:fibo(n-1)+fibo(n-2);
}
int main()
{
	int n;
	cin>>n;
	cout<<fibo(n);
	return 0;
}
