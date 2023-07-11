#include<iostream>
using namespace std;
int main(){
	int i,j,k,s=0;
	for(i=1,j=1,k=1;i<=1000;i++,j++,k++){
		if(j==21)	j=1;
		if(k==31)	k=1;
		if(j==k){s++;cout<<i<<' '<<j<<' '<<k<<endl;}
	}
	cout<<s;
	return 0;
}
