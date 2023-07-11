#include<iostream>
#include<algorithm>
using namespace std;
int n,a[10001]={0},t[10001]={0};
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
	int i,j;
	for(i=0;i<n;i++)	t[i]==1;
	for(i=n;i>0;i--)
	{
		for(j=0;j<=i;j++){
			if(t[i*2]!=0&&a[i]<a[i*2])
				swap(a[i],a[i*2]);
			if(t[i*2+1]!=0&&a[i]<a[i*2+1])
				swap(a[i],a[i*2+1]);
		}
		swap(a[0],a[i-1]);
		t[n]==0; 
	}
}
int main()
{
	geta();
	sort(a,n);
	puta(a,n);
	return 0;
}
