#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	for(long long i=2;i*i<=n;i++){
		while(n%i==0){
			printf("%d ",i);
			n/=i;
		}
		if(n==1)	break;
	}
	if(n>1)	printf("%d",n);
	return 0;
}