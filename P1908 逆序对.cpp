#include<bits/stdc++.h>
using namespace std;
int a[500010],n;
long long m=0;
void m_sort(int l,int r){
	if(l>=r)	return;
	int mid=(l+r)/2;
	m_sort(l,mid);
	m_sort(mid+1,r);
	int i=l,j=mid+1,p=0,t[r-l+1];
	while(i<=mid&&j<=r){
		if(a[i]<=a[j])	t[p++]=a[i++];
		else			t[p++]=a[j++],m+=mid-i+1;
	}
	while(i<=mid)	t[p++]=a[i++];
	while(j<=r)		t[p++]=a[j++];
	for(i=l;i<=r;i++)
		a[i]=t[i-l];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	m_sort(1,n);
	printf("%lld",m);
	return 0;
}
