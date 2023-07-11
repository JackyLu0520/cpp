#include<iostream>
using namespace std;
int homework(int n)
{
	if(n==7)
		return 1;
	else
		return homework(n+1)+1;
}
int main() 
{
	cout<<homework(1);
	return 0;
}
