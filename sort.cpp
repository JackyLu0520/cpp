#include<bits/stdc++.h>
using namespace std;
int arr[15];
int search(int l,int r,int n,int a[]){
	int mid=l+(r-l)/2;
	if(l>r)	return l;
	if(a[mid]>n)	return search(l,mid-1,n,a);
	else	return search(mid+1,r,n,a);
} 
void print_list(int a[]){
	int i;
	for(i=0;i<10;i++){
		cout<<a[i]<<' ';
	}
	cout<<endl;
}
void bubble_sort(int a[]){
	int i,j;
	for(i=9;i>=0;i--){
		bool f=1;
		for(j=0;j<i;j++)
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
				f=0;
			}
		if(f)	break;
	}
	print_list(a);
}
void select_sort(int a[]){
	int i,j,m;
	for(i=0;i<10;i++){
		m=i;
		for(j=i;j<10;j++)
			if(a[m]>a[j])
				m=j;
		swap(a[i],a[m]);
	}
	print_list(a);
}
void insert_sort(int a[]){
	int i,j,t,p;
	for(i=1;i<10;i++){
		t=a[i],j=i-1;
		p=search(0,i-1,t,arr);
		while(j>=p){
			a[j+1]=a[j];
			j--;
		}
		if(p!=i)	a[p]=t;
	}
	print_list(a);
}
void counting_sort(int a[]){
	int b[100]={0},i,j;
	for(i=0;i<10;i++)
		b[a[i]]++;
	for(i=0,j=0;i<=100&&j<10;i++)
		while(b[i]){
			a[j]=i;
			b[i]--;
			j++;
		}
	print_list(a);
}
void q_sort(int a[],int l,int r){
	if(l>=r)	return;
	int p=a[(l+r)/2],i=l,j=r;
	while(i<=j){
		while(a[i]<=p)	i++;
		while(a[j]>=p)	j--;
		if(i<=j)	 swap(a[i],a[j]);
	}
	q_sort(a,l,j);
	q_sort(a,i,r);
}
void quick_sort(int a[]){
	q_sort(a,1,9);
	print_list(a);
}
void m_sort(int a[],int l,int r){
	if(l>=r)	return;
	int mid=(l+r)/2;
	m_sort(a,l,mid);
	m_sort(a,mid+1,r);
	int i=l,j=mid+1,p=0,t[r-l+1];
	while(i<=mid&&j<=r){
		if(a[i]<=a[j])	t[p++]=a[i++];
		else			t[p++]=a[j++];
	}
	while(i<=mid)	t[p++]=a[i++];
	while(j<=r)		t[p++]=a[j++];
	for(i=l;i<=r;i++)
		a[i]=t[i-l];
}
void merge_sort(int a[]){
	m_sort(a,0,9);
	print_list(a);
}
int main(){
	int i;
	srand(time(0));
	for(i=1;i<=10;i++){
		arr[i]=rand()%100;
	}
	print_list(arr);
	bubble_sort(arr);
	select_sort(arr);
	insert_sort(arr);
	counting_sort(arr);
	quick_sort(arr);
	merge_sort(arr);
	return 0;
}
