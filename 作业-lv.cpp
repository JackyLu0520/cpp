#include<iostream>
using namespace std;
int homework(int lv)
{
	if(lv==0)
		return 0;
	else
		return homework(lv-1)+1;
}
int main() 
{
	cout<<homework(7);
	return 0;
}
