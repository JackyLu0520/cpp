#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int a[100000]={0},x,i,j,as,n,b[100000]={0},bs;
	cin>>n;
	bs=as=1;
	a[1]=1;
	for(i=1;i<=n;i++){
		for(j=1,x=0;j<=as;j++){
			a[j]=a[j]*i+x;
			x=a[j]/10;
			a[j]%=10;
			if(x>0&&j>=as)	as++;
		}
		for(j=1,x=0;j<=max(as,bs);j++){
			b[j]=a[j]+b[j]+x;
			x=b[j]/10;
			b[j]%=10;
		}
		b[j]=x;
		if(x==0)	bs=j-1;
		else		bs=j;
	}
	for(i=bs;i>0;i--)	cout<<b[i];
	return 0;
}
