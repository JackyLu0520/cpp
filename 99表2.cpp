#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int i,j;
	for(i=1;i<=9;i++)
	{
		if(i==1)
			cout<<"¨X";
		else
			cout<<"¨d";
		for(j=1;j<=i-1;j++)
			cout<<"¨T¨T¨T¨T¨p";
		cout<<"¨T¨T¨T¨T¨["<<endl;
		cout<<"¨U";
		for(j=1;j<=i;j++)
			cout<<" "<<j<<"¡Á"<<i<<"="<<setw(2)<<i*j<<"¨U";
		cout<<endl;
	}
	cout<<"¨^";
	for(j=1;j<=8;j++)
		cout<<"¨T¨T¨T¨T¨m";
	cout<<"¨T¨T¨T¨T¨a"<<endl;
	return 0;
}
