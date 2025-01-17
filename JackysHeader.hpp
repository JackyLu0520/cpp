#include<cmath>
#define for1(i,begin,end,n) for(i=begin;i<=end;i+=n)
#define uint unsigned int
#define ll long long
int max1(int a[],int n)
{
	return n==1?a[n]:max(max1(a,n-1),a[n]); 
}
bool isPrime(int n)
{
	int i;
	if(n==1||n%2==0&&n>2)
		return false;
	if(n==2)
		return true;
	for(i=3;i*i<=n;i+=2)
		if(n%i==0)
			return false;
	return true; 
}
bool isPalindrome(int num)
{
	int m=0,n=num;
	while(n)	{m=m*10+n%10;n/=10;}
	return m==num;
}
bool isLeap(int year)
{
	return year%400==0||year%4==0&&year%100!=0;
}
unsigned int gcd(unsigned int a,unsigned int b)
{
	return b?gcd(b,a%b):a;
}
