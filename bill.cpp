#include<iostream>
#include<string>
using namespace std;
int main()
{
	const string USER="20090520ljq��2019ע��",PSW="ljq0520";
	string user,psw;
	cin>>user>>psw;
	if(user==USER) 
		if(psw==PSW)
			cout<<"��ӭ!";
		else
			cout<<"�������";		 
	else
		cout<<"�û�������";  
} 
