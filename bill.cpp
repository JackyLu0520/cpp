#include<iostream>
#include<string>
using namespace std;
int main()
{
	const string USER="20090520ljq£º2019×¢²á",PSW="ljq0520";
	string user,psw;
	cin>>user>>psw;
	if(user==USER) 
		if(psw==PSW)
			cout<<"»¶Ó­!";
		else
			cout<<"ÃÜÂë´íÎó£¡";		 
	else
		cout<<"ÓÃ»§Ãû´íÎó£¡";  
} 
