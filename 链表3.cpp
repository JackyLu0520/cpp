#include<iostream>
using namespace std;
int data[101],r[101];
int main(){
	int i,n,t,len;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>data[i];
	len=n;
	for(i=1;i<=n;i++)
		r[i]=i+1;
	r[n]=0;
	
	len++;
	cin>>data[len];
	t=1;
	while(t!=0){
		if(data[r[t]]>data[len]){
			r[len]=r[t];
			r[t]=len;
			break;
		}
		t=r[t];
	}
	
	t=1;
	while(t!=0){
		cout<<data[t]<<' ';
		t=r[t];
	}
	return 0;
}
