#include<iostream> 
#include<string>
using namespace std;
struct stud
{
	string name;
	int c,m,e;
}s[1000];
int main()
{
	int n,i;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>s[i].name>>s[i].c>>s[i].m>>s[i].e;
	for(i=1;i<=n;i++)
		if(s[0].c+s[0].m+s[0].e<s[i].c+s[i].m+s[i].e)
		{
			s[0].name=s[i].name;
			s[0].c=s[i].c;
			s[0].m=s[i].m;
			s[0].e=s[i].e;
		}
	cout<<s[0].name<<' '<<s[0].c<<' '<<s[0].m<<' '<<s[0].e;
}
