#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str,str1;
	int i,j,a;
	cin>>str;
	for(i=0;i<str.size();i++)
	{
		a=0;
		for(j=0;j<str.size();j++)
		{
			if(str[i]==str[j]&&i!=j)
			{
				a++;
			}
		}
		if(!(a))
		{
			str1=str[i];
			break;
	    }
	}
	if(a)
		str1="no";
	cout<<str1;
	return 0;
} 
