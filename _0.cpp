#include<iostream>
using namespace std;
int main()
{
	int i=0,t=0;
	while(1)
	{
		t++;
		i+=3;
		if(i>=17)
		    break;
		else
		{
			t++;
			i--;
		}
	}
	cout<<t;
	return 0;
}
