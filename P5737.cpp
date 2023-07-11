#include<iostream>
using namespace std;
bool isleap(int year)
{
	return (year%400==0||year%4==0&&year%100!=0);
}
int main()
{
	int x,y,i,s=0;
	bool b[3001]={false};
	cin>>x>>y;
	for(i=x;i<=y;i++)
		if(isleap(i))
		{
			s++;
			b[i]=true;
		}
	cout<<s<<endl;
	for(i=1;i<=3000;i++)
		if(b[i])
			cout<<i<<' ';
	return 0;
}
