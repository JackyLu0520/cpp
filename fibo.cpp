#include<iostream>
using namespace std;
long long fibo(int n){
	long long f1=1,f2=1,f3=1;
	int i;
	for(i=3;i<=n;i++){
		f3=f1+f2;
		f1=f2;
		f2=f3;
	}
	return f3;
}
/*
long long fibo(int n){
	return n<3?1:fibo(n-1)+fibo(n-2);
}
*/
int main(){
	int n;
	cin>>n;
	cout<<fibo(n);
	return 0;
}
