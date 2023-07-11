#include<iostream>
using namespace std;
int main(){
	int a[100000]={0},x,i,j,as,n,m;
	cin>>n>>m;
	as=1;
	a[1]=1;
	for(i=1;i<=m;i++){
		for(j=1,x=0;j<=as;j++){
			a[j]=a[j]*n+x;
			x=a[j]/10;
			a[j]%=10;
			if(x>0&&j>=as)	as++;
		}
	}
	for(i=as;i>0;i--)	cout<<a[i];
	return 0;
}
