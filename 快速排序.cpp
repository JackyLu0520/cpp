#include<iostream>
#include<algorithm>
using namespace std;
int a[10000];
void qsort(int l,int r){
	int i=l,j=r,t=a[(l+r)/2];
	do{
		while(a[i]<t)	i++;
		while(a[j]>t)	j--;
		if(i<=j)
		{swap(a[i],a[j]);i++;j--;}
	}while(i<=j);
	if(l<j)	qsort(l,j);
	if(i<r)	qsort(i,r);
}
int main(){
	int n,i;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	qsort(1,n);
	for(i=1;i<=n;i++)
		cout<<a[i]<<' ';
	return 0;
}
