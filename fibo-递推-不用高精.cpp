#include<bits/stdc++.h>
using namespace std;
unsigned long long a,b,c;
int n;
int main(){
	cin>>n;
	a=b=1;
	for(int i=3;i<=n;i++){
		c=a+b;
		a=b;
		b=c;
	}
	cout<<b;
	return 0;
}
