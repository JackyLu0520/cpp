#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d,e,n;
	cin>>a>>b>>c>>d>>e;
	cin>>n;
	switch(n)
	{
		case 1:cout<<a;break;
		case 2:cout<<b;break;
		case 3:cout<<c;break;
		case 4:cout<<d;break;
		case 5:cout<<e;break;
		default:cout<<"x";
    }
    return 0;
}
