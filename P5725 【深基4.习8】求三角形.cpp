#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin>>n;
	for(int i=1;i<=n*n;i++){
		printf("%02d",i);
		if(i%n==0)	cout<<endl;
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2*(n-i);j++)
			cout<<' ';
		for(int j=1;j<=i;j++)
			printf("%02d",i*(i-1)/2+j);
		cout<<endl;
	}
	return 0;
}