#include<iostream>
using namespace std;
int ans,a[5];
int max(int x,int y)
{
	if(x>y)return x;
	else return y;	
}
void fun(void)
{
	int i;
	for(i=1;i<=5;i++)
		cin>>a[i];
	ans=a[0];
	for(i=1;i<5;i++)
		ans=max(ans,a[i]);
}
int main()
{
	fun();
	cout<<ans;	
	return 0;	
}
