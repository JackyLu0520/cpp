#include<iostream>
using namespace std;
int main()
{
	int a[5],i,b;
	for(i=0;i<5;i++)
		cin>>a[i];
	while(1)
	{
		cin>>b;
		if(b==-1)
			break;
		else if(b>5||b<-1)
			cout<<"?"<<endl;
		else
		    cout<<a[b-1]<<endl;
	}
	return 0;
} 
