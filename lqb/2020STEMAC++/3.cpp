#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,a[6];
	for(i=1;i<=5;i++)
		cin>>a[i];	 
	for(i=1;i<=4;i++)
		for(j=1;j<=5-i;j++)
			if(a[j+1]>a[j])
				swap(a[j],a[j+1]);
    for(i=1;i<5;i++)
    	cout<<a[i]<<",";
    cout<<a[5];
    return 0;
}
