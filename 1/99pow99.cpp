///99 µÄ 99´Î·½
#include <iostream>
using namespace std;
const int mm=99;
int  a[10000],i,p,x;
int main()
{
	for (p=1; p<=mm-1; p++) a[i]=0;
	a[0]=9; 
	a[1]=9; 
	for (i=2; i<=mm; i++)  
	{
		for (p=0; p<=mm-1; p++) a[p]=a[p]*99; 
		for (p=0; p<=mm-2; p++)
		{
			x=a[p];
			a[p]=x%10;  
			a[p+1]+=x/10;
		}
	}
	for (p=mm-1; p>=0; p--) cout<<a[p];
	return 0;
}

