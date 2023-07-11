#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int n,i,a,sum=0,Min=2147483646,Max=-2147483647;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a;
		if(Min>a)	Min=a;
		if(Max<a)	Max=a;
		sum+=a;
	}
	cout<<Max<<' '<<Min<<' '<<fixed<<setprecision(2)<<sum*1.0/n;
	return 0;
}
