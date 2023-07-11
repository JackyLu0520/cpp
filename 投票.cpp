#include<iostream>
#define MAX 5
using namespace std;
int a[MAX+1];
void count(int n)
{
	int x;
	for(int i=1;i<=n;i++)
	{
		cout<<i<<':';
		cin>>x;
		a[x]++;
	}
}
int main()
{
	int i,n,*p;
	cin>>n;
	for(p=a;p<=(a+MAX);p++)
		*p=0;
	count(n);
	for(i=0;i<=MAX;i++)
	{
		if(!i)	cout<<"ÆúÈ¨:"<<a[i]<<endl;
		else	cout<<i<<':'<<a[i]<<endl;
	}
	return 0;
}
