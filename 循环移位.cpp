#include<iostream>
using namespace std;
int main(){
	int a[6]={0,1,2,3,4,5},i,j;
	for(i=1;i<=10;i++){
		cout<<i<<": "<<a[1]<<a[2]<<a[3]<<a[4]<<a[5]<<endl;
		for(j=0;j<5;j++)
			a[j]=a[j+1];
		a[5]=a[0];
	}
	return 0;
}
