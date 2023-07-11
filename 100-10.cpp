#include<iostream>
using namespace std;
int main()
{
	int a[100],i,j;
	for(i=0;i<100;i++)
		cin>>a[i];
	for(i=0;i<10;i++)
		for(j=0;j<100-i;i++)
			if(a[j+1]>a[j])	
				swap(a[j+1],a[j]); 
	cout<<a[89];
}
