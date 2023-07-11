#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a,b,c,m,n;
	cin>>a>>b>>c;
	m=max(a,max(b,c));
	n=min(a,min(b,c));
	cout<<n/__gcd(m,n)<<'/'<<m/__gcd(m,n);
	return 0;
}
