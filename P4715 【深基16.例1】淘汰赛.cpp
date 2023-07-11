#include<bits/stdc++.h>
using namespace std;
int a[1<<8][2],n;
int main(){
	int i;
	cin>>n;
	for(i=(1<<n);i<(1<<(n+1));i++){
		cin>>a[i][1];
		a[i][0]=i-(1<<n)+1;
	}
	for(i=(1<<n)-1;i>=1;i--)
		if(a[2*i][1]>a[2*i+1][1]){
			a[i][1]=a[2*i][1];
			a[i][0]=a[2*i][0];
		}
		else{
			a[i][1]=a[2*i+1][1];
			a[i][0]=a[2*i+1][0];
		}
	if(a[2][1]<a[3][1])
		cout<<a[2][0];
	else
		cout<<a[3][0];
	return 0;
} 
