#include<bits/stdc++.h>
using namespace std;
int n,m,a[4000010],Max=0,mi,mj;
long long sum;
int main(){
	int i=1,j=1;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	i=1,j=1;
	while(i<=n){
		while(j<=n&&sum+a[j]<=m)
			sum+=a[j++];
		if(sum>Max)
			Max=sum,mi=i,mj=j-1;
		sum-=a[i++];
	}
	printf("%d %d %d",mi,mj,Max);
	return 0;
}
