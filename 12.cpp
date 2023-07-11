#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int a,b,c,d,e,f,g,h,i;
	cin>>a>>b;
	c=a/b;
	cout<<setw(5)<<c<<endl;
	cout<<setw(5)<<"---"<<endl;
	cout<<b<<"/"<<a<<endl;
	d=c/100*b;
	cout<<setw(3)<<d<<endl;
	cout<<" ----"<<endl;
	e=(a/100-d)*10+(a%100/10);
	cout<<setw(4)<<e<<endl;
	f=e/b*b;
	cout<<setw(4)<<f<<endl;
	cout<<" ----"<<endl;
	g=(e-f)*10+(a%100%10);
	cout<<setw(5)<<g<<endl;
	h=g/b*b;
	cout<<setw(5)<<h<<endl;
	cout<<" ----"<<endl;
	i=g-h;
	cout<<setw(5)<<i;
	return 0;
}
