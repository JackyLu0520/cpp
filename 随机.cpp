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
	  cout<<"中奖了，";
	else
	  cout<<"没中奖，";
	cout<<"号码是"<<a<<"。" ;
	return 0;    
}
