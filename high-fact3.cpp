#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int main(){
	string s1;
	int a[100000]={0},b,x,i,j,as,n=10000;
	cin>>n;
	as=1;
	a[1]=1;
	b=n;
	for(i=1;i<=n;i++,b--){
		for(j=1;j<=as;j++){
			a[j]*=i;
			a[j]+=a[j-1]/10;
			a[j-1]%=10;
			if(a[j]>9&&j>=as)	as++;
		}
	}
	for(i=as;i>0;i--)	cout<<a[i];
	return 0;
}
