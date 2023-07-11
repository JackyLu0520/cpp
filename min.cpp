#include<iostream>
#include<cmath>
using namespace std;
int arr[1000],n;
int maxarr(int lv)
{
	if(lv==0)
		return arr[lv];
	else
		return min(maxarr(lv-1),arr[lv]);
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<maxarr(n-1);
	return 0;
}
