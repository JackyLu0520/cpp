#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
int main()
{
	bool f[4];
	cout<<"请在心里选1~15中的一个数，记好。"<<endl; 
	system("pause");
	system("cls");
	cout<<"请问这个数是单数吗？回答1或0。";
	cin>>f[0];
	system("cls");
	cout<<"请问这个数在2,3,6,7,10,11,14,15中吗？回答1或0。";
	cin>>f[1];
	system("cls");
	cout<<"请问这个数在4,5,6,7,12,13,14,15中吗？回答1或0。";
	cin>>f[2];
	system("cls");
	cout<<"请问这个数在8,9,10,11,12,13,14,15中吗？回答1或0。";
	cin>>f[3];
	system("cls");
	cout<<"你想的数是："<<pow(2,3)*f[3]+pow(2,2)*f[2]+pow(2,1)*f[1]+pow(2,0)*f[0]<<endl;
	system("pause");
	return 0;
}
