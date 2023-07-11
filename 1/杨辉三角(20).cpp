#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int t[22][22],i,j;
	for(i=1;i<=20;i++)
	{
		t[i][1]=t[i][i]=1;
		for(j=2;j<i;j++)
			t[i][j]=t[i-1][j-1]+t[i-1][j];
	}
	for(i=1;i<=20;i++)
	{
		for(j=1;j<=20-i;j++)	cout<<"   ";
		for(j=1;j<=i;j++)
			cout<<setw(6)<<t[i][j];
		cout<<endl;
	}
} 
