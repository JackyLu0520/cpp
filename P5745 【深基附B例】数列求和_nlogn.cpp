#include<bits/stdc++.h>
using namespace std;
int n,m,a,Max=0,mi,mj;
long long sum,s[4000010]={0};
int search(int l,int r,long long x){
	int mid=l+(r-l)/2;
	if(l==r)	if(s[l]==x)	return l;
				else		return l-1;
	if(s[mid]>=x)	return search(l,mid,x);
	else			return search(mid+1,r,x);
}
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		s[i]=s[i-1]+a;
	}
	for(i=1;i<=n;i++){
		j=search(i,n,s[i-1]+m);
		sum=s[j]-s[i-1];
		if(sum>Max&&sum<=m)
			Max=sum,mi=i,mj=j;
	}
	printf("%d %d %d",mi,mj,Max);
	return 0;
}
