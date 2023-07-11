#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int x,y;
	cin>>x;
	y=x/5;
	if(x%5!=0)
		y+=1;
	cout<<y<<endl;
	y=ceil(x/5.0);
	cout<<y;
	return 0; 
}
