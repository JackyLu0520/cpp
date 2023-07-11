#include<iostream>
using namespace std;
int main(){
	int n,c=0,i;
	cin>>n;
	for(i=2;i<n;i++)
		while(n%i==0){
			n/=i;
			c++;
		}
	cout<<c;
	return 0;
}
