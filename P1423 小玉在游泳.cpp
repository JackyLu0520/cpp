#include<bits/stdc++.h>
using namespace std;
double d,d1=0,sd=2;
int main(){
	int i;
	cin>>d;
	for(i=1;d1<d;i++)	d1+=sd,sd*=0.98;
	cout<<i-1;
	return 0;
}
