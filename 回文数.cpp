#include<iostream>
using namespace std;
bool isPalindrome(int num)
{
	int m=0,n=num;
	while(n)	{m=m*10+n%10;n/=10;}
	return m==num;
}
int main()
{
	int n;
	cin>>n;
	cout<<isPalindrome(n);
	return 0;
}
