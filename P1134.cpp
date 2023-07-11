#include<iostream>
using namespace std;
int main(){
	unsigned long long nt=1;
	int i,n;
	cin>>n;
	for(i=1;i<=n;i++){
		for(nt*=i;nt%10==0;nt/=10)	;
		nt%=10000000000;
	}
	cout<<nt%10;
	return 0;
} 
