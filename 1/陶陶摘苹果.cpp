#include<iostream>
using namespace std;
int main()
{
	int ah[10],h,a,i;
	for(i=0;i<10;i++)	cin>>ah[i];
	cin>>h;
	h+=30;
	for(i=0;i<10;i++)
		if(ah[i]<=h)
			a++;
	cout<<a;
	return 0;
}
