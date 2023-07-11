#include<iostream>
using namespace std;
int main()
{
	int head,leg,i,j;
	cin>>head>>leg;
	for(i=1;i<head;i++)
	{
		j=head-i;
	    if(i*2+j*4==leg)
			cout<<i<<endl<<j;
	}
	//cout<<head-(leg/2-head)<<endl<<leg/2-head;
    return 0;
}
