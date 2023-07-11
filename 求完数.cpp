#include<iostream>
using namespace std;
int main(){
	int n,sum,i,j,c=0;
	cin>>n;
	for(i=1;i<n;i++){
		sum=0;
		for(j=1;j<i;j++)
			if(i%j==0)
				sum+=j;
		if(sum==i){
			cout<<i<<endl;
			c++;
		}
	}
	cout<<'*'<<c;
	return 0;
}
