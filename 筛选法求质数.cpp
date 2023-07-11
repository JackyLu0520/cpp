#include<iostream>
using namespace std;
int main(){
	int a[101]={0},i,j;
	for(i=2;i<=100;i++)
		if(a[i]==0)
			for(j=2*i;j<=100;j+=i)
				a[j]=1;
	for(i=2;i<=100;i++)
		if(a[i]==0)
			cout<<i<<' ';
	return 0;
}
