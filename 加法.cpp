#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
	int a,b,c;
	srand(time(0)); 
	a=rand()%90+10;
	b=rand()%90+10;
	cout<<a<<"+"<<b<<"=";
	cin>>c;
	if(a+b==c)
	  cout<<"Yes";
    else
      cout<<"No";
    return 0;
} 
