#include<iostream>
using namespace std;
int main(){
	bool a[10]={0};
	int i,n=0;
	for(i=1;i<=1000;i++){
		n=(n+i)%10;
		a[n]=1;
	}
	for(i=1;i<=9;i++)
		if(!a[i])
			cout<<i<<' ';
	return 0;
}
