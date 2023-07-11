#include<iostream>
#include<string>
using namespace std;
int main()
{
	string st1,st2;
	int a,b,i;
	cin>>st1>>st2;
	for(i=0;i<st1.size();i++)
		a*=st1[i]-64;
	for(i=0;i<st2.size();i++)
		b*=st2[i]-64;
	if(a%47==b%47)
		cout<<"GO";
	else
		cout<<"STAY";
	return 0;
}
