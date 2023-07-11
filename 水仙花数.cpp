#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int i,j,k;
	for(i=1;i<10;i++)
		for(j=0;j<10;j++)
			for(k=0;k<10;k++)
				if(pow(i,3)+pow(j,3)+pow(k,3)==i*100+j*10+k)
					cout<<i*100+j*10+k<<'\t';
	return 0;
}
