#include<bits/stdc++.h>
using namespace std;
int a[100010],n;
void q_sort(int l,int r){
	int p=a[(l+r)/2],i=l,j=r;
	while(i<=j){
		while(a[i]<p)	i++;
		while(a[j]>p)	j--;
		if(i<=j)	{swap(a[i],a[j]);i++;j--;}
	}
	if(l<j)	q_sort(l,j);
	if(i<r)	q_sort(i,r);
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	q_sort(0,n-1);
	for(int i=0;i<n;i++)
		cout<<a[i]<<' ';
	return 0;
}

