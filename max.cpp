#include<iostream>
using namespace std;
int ans,a[5];
int max1(int x,int y)
{
	if(x>y)
		return x;
	else
		return y;
}
int maxa()
{
	ans=a[0];
	for(int i=1;i<5;i++)
		ans=max(ans,a[i]);
	return ans;
}
int main()
{
	cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4];
	cout<<maxa();
	return 0;
}
