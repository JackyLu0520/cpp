#include<iostream>
using namespace std;
int main(){
	long long num=0,sum=0,n,i,t;
	cin>>n;
	for(i=1;i<=n;i++){
		t=i;
		while(t%5==0){
			num++;
			t/=5;
		}
		sum+=num;
	}
	cout<<sum;
	return 0;
}
