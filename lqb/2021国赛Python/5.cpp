#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,a[10000],m,s,i;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	s=m=a[1];
	for(i=2;i<=n;i++){
		m=min(m,a[i]);
		s+=a[i];
	}
	cout<<s-n*m;
	return 0;
}
