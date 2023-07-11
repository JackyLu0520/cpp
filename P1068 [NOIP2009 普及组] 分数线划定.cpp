#include<bits/stdc++.h>
using namespace std;
struct P{
	int k,s;
}p[5010];
int n,m,l;
bool cmp(P a,P b){
	if(a.s==b.s)	return a.k<b.k;
	return a.s>b.s;
}
int main(){
	int i;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>p[i].k>>p[i].s;
	sort(p+1,p+n+1,cmp);
	l=p[int(m*1.5)].s;
	for(i=m*1.5;p[i].s==l;i++);
	cout<<l<<' '<<i-1<<endl;
	for(int j=1;j<i;j++)
		cout<<p[j].k<<' '<<p[j].s<<endl;
	return 0;
}