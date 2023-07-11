#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	int i,j;
	string s;
	getline(cin,s);
	bool a[s.size()];
	memset(a,true,sizeof(a));
	for(i=0;i<s.size();i++)
		if(a[i])
			for(j=i+1;j<s.size();j++)
				if(s[i]==s[j])
					a[i]=a[j]=false;
	for(i=0;i<s.size();i++)
		if(a[i])
		{
			cout<<s[i];
			return 0;
		}
	cout<<"No";
	return 0;
}
