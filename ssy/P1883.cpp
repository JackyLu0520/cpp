#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const double eps=1e-9;
int t,n,a[N],b[N],c[N];
double f(double x){
	double Max=-0x3f3f3f3f;
	for(int i=1;i<=n;i++)
		Max=max(Max,a[i]*x*x+b[i]*x+c[i]);
	return Max;
}
double search(double l,double r){
	while(r-l>=eps){
		double lmid=(l*2+r)/3,rmid=(l+r*2)/3;
		if(f(lmid)>f(rmid))	l=lmid;
		else				r=rmid;
	}
	return l;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
		printf("%.4lf\n",f(search(0,1000)));
	}
	return 0;
}