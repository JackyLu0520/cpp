#include<iostream>
using namespace std;
void add(int a[],int b[],int c[]){
	int i,x;
	for(i=1,x=0;i<=b[0];i++){
		c[i]=a[i]+b[i]+x;
		x=c[i]/10;
		c[i]%=10;
	}
	c[i]=x;
	if(c[i]==0)	c[0]=i-1;
	else		c[0]=i;
}
void set(int a[],int b[]){
	for(int i=0;i<=b[0];i++)	a[i]=b[i];
}
void print(int a[]){
	for(int i=a[0];i>=1;i--)	cout<<a[i];
}
int main(){
	int n,i,f1[10000]={0},f2[10000]={0},f3[10000]={0};
	cin>>n;
	f1[0]=f2[0]=f3[0]=f1[1]=f2[1]=f3[1]=1;
	for(i=3;i<=n;i++){
		add(f1,f2,f3);
		set(f1,f2);
		set(f2,f3);
	}
	print(f3);
	return 0;
}
