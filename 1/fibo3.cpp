#include<cstdio>
using namespace std;
int main(){
	long long a[2]={1,0},b[2]={1,0},c[2],i,n;
	scanf("%d",&n);
	for(i=3;i<=n;i++){
		c[0]=(a[0]+b[0])%100000000000;
		c[1]=a[1]+b[1]+(a[0]+b[0])/100000000000;
		a[0]=b[0];a[1]=b[1];
		b[0]=c[0];b[1]=c[1];
	}
	printf("%d%011d",c[1],c[0]);
	return 0;
}
