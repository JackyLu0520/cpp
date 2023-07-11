#include<iostream>
using namespace std;
bool isleap(int year)
{
	return (year%400==0||year%4==0&&year%100!=0);
}
int main()
{
	int y;
	cin>>y;
	cout<<isleap(y)?1:0;
	return 0;
}
