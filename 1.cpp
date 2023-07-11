#include<iostream>
#include<cstring> 
using namespace std;		
int main()
{ 
	bool a[100];
	int i,j;
	memset(a,true,sizeof(a));
	a[0]=false;
	for(i=1;i<100;i++)
		for(j=1;j<100;j++)
			if(j%i==0)
				a[j]=false;
	for(i=0;i<100;i++)
		if(a[i])
			cout<<i+1<<' ';
	return 0;
} 
