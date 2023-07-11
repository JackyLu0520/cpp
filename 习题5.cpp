#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int i,j,n,k;
	cin>>n>>k;
	float a[2][n+1];
	for(i=1;i<=n;i++)
		cin>>a[0][i]>>a[1][i];	 
	for(i=1;i<=n-1;i++)
		for(j=1;j<=n-i;j++)
			if(a[1][j+1]>a[1][j])
			{
				swap(a[1][j],a[1][j+1]);
				swap(a[0][j],a[0][j+1]);
			}
    printf("%d %g",(int)(a[0][k]),a[1][k]);
    return 0;
}
