#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	long long t[11][11];
	int i,j;
	for(i=1;i<=10;i++)
	{
		t[i][1]=t[i][i]=1;
		for(j=2;j<i;j++)
			t[i][j]=t[i-1][j-1]+t[i-1][j];
	}
	for(i=1;i<=10;i++)
	{
		for(j=1;j<=10-i;j++)	cout<<"  ";
		for(j=1;j<=i;j++)	 cout<<setw(4)<<t[i][j];
		cout<<endl;
	}
	return 0;
}
