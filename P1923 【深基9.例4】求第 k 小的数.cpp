#include<bits/stdc++.h>
using namespace std;
int a[5000010],n,k;
int findk(int l,int r){
	int p=a[(l+r)/2],i=l,j=r;
	while(i<=j){
		while(a[i]<p)	i++;
		while(a[j]>p)	j--;
		if(i<=j)	{swap(a[i],a[j]);i++;j--;}
	}
	if(k<=j)	return findk(l,j);
	if(k>=i)	return findk(i,r);
	return p;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("%d",findk(0,n-1));
	return 0;
}

