#include<iostream>
#include"JackysHeader.hpp"
using namespace std;
int main()
{
	int i,num=1;
	cout<<"int p[781]={2,";
	for(i=3;i<=100000000;i+=2)
		if(isPalindrome(i))
			if(isPrime(i))
			{
				cout<<i<<',';
				num++;
			}
	cout<<"};"<<endl;
	cout<<num;
	return 0;
}
