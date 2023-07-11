#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int main(){
	string s1;
	int a[100000]={0},x,i,j,as;
	long long n,b;
	cin>>n;
	as=1;
	b=n;
	for(i=1;i<=n;i++,b--){
		a[1]+=b;
		for(j=1;j<=as;j++){
			a[j+1]+=a[j]/10;
			a[j]%=10;
			if(a[j+1]>0&&j>=as)	as++;
		}
	}
	for(i=as;i>0;i--)	cout<<a[i];
	return 0;
}
