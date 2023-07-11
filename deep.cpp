#include<iostream>
#include<string>
using namespace std;
int main()
{
	int h,s;
	string cmd;
	cin>>h>>s;
	cin>>cmd;
	for(int i=0;i<cmd.size();i++)
	{
		if(cmd[i]='u'&&s!=0)    s--;
		if(cmd[i]='d'&&s!=h)    s++;
		cout<<cmd[i];
	}
	
	return 0;
} 
