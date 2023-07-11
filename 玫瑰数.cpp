#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int i,j,k,l;
	for(i=1;i<10;i++)
		for(j=0;j<10;j++)
			for(k=0;k<10;k++)
				for(l=0;l<10;l++)
					if(pow(i,4)+pow(j,4)+pow(k,4)+pow(l,4)==i*1000+j*100+k*10+l)
						cout<<i*1000+j*100+k*10+l<<'\t';
	return 0;
}
