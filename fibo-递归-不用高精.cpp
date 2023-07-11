#include<bits/stdc++.h>
using namespace std;
unsigned long long fibo(int n){
	if(n==1||n==2)	return 1;
	else			return fibo(n-1)+fibo(n-2);
}
int n;
int main(){
	cin>>n;
	cout<<fibo(n);
	return 0;
}
