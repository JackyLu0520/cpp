#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	scanf("%d",&t);
	while(t--){
		int a,b,c;
		scanf("%d%d",&a,&b);
		c=__gcd(a,b);
		a/=c;
		b/=c;
		if(b==1)	printf("0\n");
		else{
			while(b&&b%5==0)	b/=5;
			if(b==1)	{printf("1\n");continue;}
			while(b&&b%2==0)	b/=2;
			if(b==1)	printf("1\n");
			else		printf("2\n");
		}
	}
	return 0;
}