#include<iostream>
using namespace std;
int main(){
	int i,k,num,n,m;
	cin>>n>>m;
	bool a[101]={0};
	for(i=1,k=0,num=0;num!=n;i++){
		if(i>n)		i=1;
		if(!a[i])	k++;
		if(k==m){
			a[i]=1;
			num++;
			k=0;
			cout<<i<<' ';
		}
	}
	return 0;
}
