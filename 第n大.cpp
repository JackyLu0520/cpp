#include<iostream>
using namespace std;
int maxn(int a[],int m){
	int x,num,i=0;
	do{
		x=a[i];
		num=0;
		for(int j=0;j<10;j++)
			if(x<a[j])
				num++;
		i++;
	}while(num!=m-1);
	return x;
}
int main(){
	int n,a[10];
	for(int i=0;i<10;i++)
		cin>>a[i];
	cin>>n;
	cout<<maxn(a,n);
	return 0;
}
