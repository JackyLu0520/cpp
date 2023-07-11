#include<bits/stdc++.h>
using namespace std;
struct P{
	int c;
	float h;
}a[11];
bool cmp(P a,P b){
	return a.h<b.h;
}
int main(){
	for(int i=1;i<=10;i++)
		cin>>a[i].h;
	for(int i=1;i<=10;i++)
		cin>>a[i].c;
	sort(a+1,a+11,cmp);
	for(int i=1;i<=10;i++)
		if(a[i].c==1)
			cout<<fixed<<setprecision(2)<<a[i].h<<' ';
	for(int i=10;i>=1;i--)
		if(a[i].c==2)
			cout<<fixed<<setprecision(2)<<a[i].h<<' ';
	return 0;
}
