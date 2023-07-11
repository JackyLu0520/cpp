#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	int n,p[3][2],a,b,c;
	cin>>n>>p[0][0]>>p[0][1]>>p[1][0]>>p[1][1]>>p[2][0]>>p[2][1];
	a=ceil(n*1.0/p[0][0])*p[0][1];
	b=ceil(n*1.0/p[1][0])*p[1][1];
	c=ceil(n*1.0/p[2][0])*p[2][1];
	cout<<min(a,min(b,c));
	return 0;
}
