#include<bits/stdc++.h>
using namespace std;
int a[100010],n;
void qsort(int l,int r){
	int p=a[(l+r)/2],i=l,j=r;
	while(i<=j){
		while(a[i]>p)	i++;
		while(a[j]<p)	j--;
		if(i<=j)	swap(a[i++],a[j--]);
	}
	if(l<j)	qsort(l,j);
	if(i<r)	qsort(i,r);
}
int main(){
	int i;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	qsort(0,n-1);
	for(i=0;i<n;i++)
		cout<<a[i]<<' ';
	return 0;
}
