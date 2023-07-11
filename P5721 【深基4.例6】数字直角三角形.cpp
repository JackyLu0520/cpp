#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	int i,j,k;
	cin>>n;
	for(i=1,k=1;i<=n;i++){
		for(j=1;j<=n-i+1;j++,k++)
			printf("%02d",k);
		cout<<endl;
	}
	return 0;
}
