#include<iostream>
using namespace std;
int main()
{
	int n,a=0,b,i,ans=0,max1=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>b;
		if(a<b)
			ans++;
		else
			ans=1;
		if(max1<ans)
			max1=ans;
		a=b;
	}
	cout<<max1;
	return 0;
}//P1567
/*#include<iostream>
using namespace std;
int main()
{
	int n,a=0,b,i,ans=0,max1=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>b;
		if(a+1=b)
			ans++;
		else
			ans=1;
		if(max1<ans)
			max1=ans;
		a=b;
	}
	cout<<max1;
	return 0;
}//P1420*/
