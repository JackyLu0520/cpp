#include<iostream>
using namespace std;
long long a,b,c,n;
int main(){
	int i;
	cin>>n;
	if(n==0){
		cout<<"0.00";
		return 0;
	}
	a=1,b=1;
	for(i=3;i<=n;i++){
		c=a+b;
		a=b;
		b=c;
	}
	cout<<b<<".00";
	return 0;
} 
