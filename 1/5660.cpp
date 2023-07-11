#include<iostream>
#include<string>
using namespace std;
int main()
{
	string st;
	cin>>st;
	int i,ans=0;;
	for(i=0;i<st.size();i++)
		if(st[i]=='1')
			ans++;
	cout<<ans;
	return 0;
}
