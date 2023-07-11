#include<iostream>
using namespace std;
int main(){
	double n;
	int a,b,c,d;
	cin>>n;
	a=int(n/100)%10;
	b=int(n/10)%10;
	c=int(n/1)%10;
	d=int(n*10)%10;
	cout<<d<<'.'<<c<<b<<a<<endl;
	return 0;
}
