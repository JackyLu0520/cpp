#include<iostream>
using namespace std;
int n,a[10001];
void geta()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
}
void puta(int a[],int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<' ';
}
void sort(int a[],int n)
{
	int i,j,gap=n/2;
	while(gap)
	{
		for(i=gap;i<n;i++)
			for(j=i;j>=gap;j-=gap)
				if(a[j]<a[j-gap])
					swap(a[j],a[j-gap]);
		gap/=2;
	} 
}
int main()
{
	geta();
	sort(a,n);
	puta(a,n);
	return 0;
}
