#include<iostream>
using namespace std;
int main()
{
	int s=0;
	for(int i=1;i<=1000;i++)
		if(i%10==7||i/10%10==7||i/100==7)
		{
			cout<<i<<'\t';
			s++;
		}
	cout<<endl<<s;
	return 0;
}
