#include<iostream>
using namespace std;
int a[100001];
int qsort(int l,int r)
{
	int i=l,j=r,mid=a[(l+r)/2];
	do
	{
		while(a[i]<mid)	i++;
		while(a[j]>mid)	j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}while(i<=j);
	if(l<j)	qsort(l,j);
	if(i<r)	qsort(i,r);
} 
int main()
{
	int n,i;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	qsort(1,n);
	for(i=1;i<=n;i++)
		cout<<a[i]<<' ';
	return 0;
}
