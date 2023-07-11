#include<iostream>
#include<cmath>
using namespace std;
int arr[1000],n;
int maxarr(int lv,int arr[])
{
	return lv==0?arr[lv]:max(maxarr(lv-1,arr),arr[lv]);
}
int main()
{
	int arr[1000],n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<maxarr(n-1,arr);
	return 0;
}
