#include<iostream>
#include<cstdlib> 
#include<ctime>
using namespace std;
int main()
{
	int a,b;
	srand(time(0));
	a=rand()%10+1;
	cin>>b;
	if(b==a)
	  cout<<"�н��ˣ�";
	else
	  cout<<"û�н���";
	cout<<"������"<<a<<"��" ;
	return 0;    
}
