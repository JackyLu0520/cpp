#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int a,b,c,d,e;
	cin>>a>>b;
	cout<<setw(5)<<a<<endl;
	cout<<"x"<<setw(4)<<b<<endl;
	cout<<"-----"<<endl;
	c=b%10*a;
	d=b/10*a;
	cout<<setw(5)<<c<<endl;
	cout<<setw(4)<<d<<endl;
	cout<<"-----"<<endl;
	e=d*10+c;
	cout<<setw(5)<<e;
	return 0; 
}
