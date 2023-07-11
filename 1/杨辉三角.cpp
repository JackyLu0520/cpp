#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int i,j,tr[11][11];
	for(i=1;i<=10;i++)
	{
		tr[i][1]=tr[i][i]=1;
		for(j=2;j<i;j++)
			tr[i][j]=tr[i-1][j-1]+tr[i-1][j];
	}
	for(i=1;i<=10;i++)
	{ 
		for(j=1;j<=10-i;j++)	cout<<"  ";
		for(j=1;j<=i;j++)
			cout<<setw(4)<<tr[i][j];
		cout<<endl;
	} 
	return 0;
}
