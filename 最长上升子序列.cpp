#include<iostream>
#include<algorithm>
using namespace std;
int n,a[1010],f[1010],Max=0;
int main(){
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++){
		f[i]=1;
		for(j=1;j<i;j++)
			if(a[j]<a[i])
				f[i]=max(f[i],f[j]+1);
	}
	for(i=1;i<=n;i++)
		Max=max(Max,f[i]);
	cout<<Max;
	return 0;
}
/*
Sample Input:
6
1 6 2 5 4 7
Sample Output:
4

£¨1 * 2 5 * 7£© 
*/
