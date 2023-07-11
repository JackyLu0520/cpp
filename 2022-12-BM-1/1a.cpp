#include<bits/stdc++.h>
using namespace std;
const int ADD=1e8+10,MAXX=2e8+20;
int t[MAXX]={0};
int main(){
	int a,b,c,d,k,cnt=0;
	cin>>a>>b>>c>>d>>k;
	for(int x1=1;x1<=k;x1++)
		for(int x2=1;x2<=k;x2++)
			t[a*x1*x1+b*x2*x2+ADD]++;
	for(int x3=1;x3<=k;x3++)
		for(int x4=1;x4<=k;x4++)
			cnt+=t[-c*x3*x3-d*x4*x4+ADD];
	cout<<cnt*16;
	return 0;
}