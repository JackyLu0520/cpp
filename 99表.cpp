#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int i,j;
	for(i=1;i<=9;i++)
	{
		if(i==1)
			cout<<"©°";
		else
			cout<<"©À";
		for(j=1;j<=i-1;j++)
			cout<<"©¤©¤©¤©¤©à";
		cout<<"©¤©¤©¤©¤©´"<<endl;
		cout<<"©¦";
		for(j=1;j<=i;j++)
			cout<<" "<<j<<"¡Á"<<i<<"="<<setw(2)<<i*j<<"©¦";
		cout<<endl;
	}
	cout<<"©¸";
	for(j=1;j<=8;j++)
		cout<<"©¤©¤©¤©¤©Ø";
	cout<<"©¤©¤©¤©¤©¼"<<endl;
	return 0;
}
