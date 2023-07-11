#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int i,j,a,b;
	cin>>b; 
	a=b+1;
	for(i=1;i<=b*2;i+=2)
	{
		a--;
		cout<<setw(a);
	    for(j=1;j<=i;j++)
	    {
	        cout<<"*";	
	    } 
	    cout<<endl;
    }
}
