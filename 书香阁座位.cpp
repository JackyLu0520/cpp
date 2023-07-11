#include<iostream>
using namespace std;
int main(){
	int n,i,s;
	for(n=15,i=1,s=15;s<312;n+=2,s+=n,i++)	{}
	cout<<i<<' '<<n;
	return 0;
}
