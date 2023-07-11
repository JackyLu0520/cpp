#include<iostream>
#include<algorithm>
using namespace std;
int n,a[101],b[101],f[101],sum;
int main(){
	int i;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	for(i=1;i<=n;i++)
		if(i==1)	f[i]=sum=a[i];
		else		f[i]=min(a[i],f[i-1]+b[i-1]),sum+=f[i];
	cout<<sum;
	return 0;
}
/*
Sample Input:
5
6 3
7 1
3 2
8 3
9 5
Sample Output:
29
*/
