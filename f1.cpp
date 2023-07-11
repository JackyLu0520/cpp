#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,s;
	while(scanf("%d",&t)==1)
		s+=t;
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

