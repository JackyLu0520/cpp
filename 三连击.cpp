#include<iostream>
using namespace std;
int a[10];
int x1,x2,x3,i;
bool f;
int main()
{
	for(x1=100;x1<=1000/3;x1++)
	{
		x2=x1*2;
		x3=x1*3;
		f=1;
		for(i=1;i<=9;i++)	a[i]=1;
		a[x1/1%10]--;
		a[x1/10%10]--;
		a[x1/100%10]--;
		a[x2/1%10]--;
		a[x2/10%10]--;
		a[x2/100%10]--;
		a[x3/1%10]--;
		a[x3/10%10]--;
		a[x3/100%10]--;
		for(i=1;i<=9;i++)	if(a[i]==1)	f=0;
		if(f)	cout<<x1<<' '<<x2<<' '<<x3<<endl;
	}
	return 0;
}
