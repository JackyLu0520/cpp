#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str1;
	int i,j,f=0;
	cin>>str1;
	int a[str1.size()];
	for(i=0;i<str1.size();i++)
	{
		a[i]=0;
	}
	for(i=0;i<str1.size();i++)
	{
		if(a[i]==0)
			for(j=i+1;j<str1.size();j++)
				if(str1[i]==str1[j])
					a[i]=a[j]=1;
		if(a[i]==0)
		{
			cout<<str1[i];
			f=1;
			break;
		}
	}
	if(!(f))
		cout<<"no";
	return 0;
} 
