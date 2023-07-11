#include<iostream>
using namespace std;
int main(){
	int a[200]={1,2},i,j,n;
	cin>>n;
	for(i=2;i<=n;i++){
		for(j=1;j<=a[0];j++)	a[j]*=2;
		a[1]+=2;
		for(j=1;j<=a[0];j++){
			a[j+1]+=a[j]/10;
			a[j]%=10;
			if(a[j+1]>0&&j>=a[0])	a[0]++;
		}
	}
	for(i=a[0];i>=1;i--)	cout<<a[i];
	return 0;
}
