#include<iostream>
#include<cmath>
using namespace std;
int arr[1000],n;
int minarr(int lv)
{
	if(lv==0)
		return arr[lv];
	else
		return min(minarr(lv-1),arr[lv]);
}
int maxarr(int lv)
{
	if(lv==0)
		return arr[lv];
	else
		return max(maxarr(lv-1),arr[lv]);
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<maxarr(n-1)-minarr(n-1);
	return 0;
}
