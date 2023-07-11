#include<iostream>
using namespace std;
void show(int);
int main()
{
	show(100);
	return 0;
}
void show(int lv)
{
	if(lv!=1)
		show(lv-1);
	cout<<lv<<' ';
}
