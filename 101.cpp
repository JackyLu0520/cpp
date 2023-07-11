#include<iostream>
using namespace std;
void show(int n,char c)
{
	int i;
	for(i=0;i<n;i++)
		cout<<c;
	cout<<endl;
}
int main()
{
	int i,n;
	char c;
	cin>>n>>c;
	for(i=0;i<n;i++)
		show(i,c);
}
