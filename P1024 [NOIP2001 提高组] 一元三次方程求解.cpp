#include<bits/stdc++.h>
using namespace std;
double a,b,c,d;
double f(double x){
	return a*x*x*x+b*x*x+c*x+d;
}
double search(double l,double r){
	if(r-l<0.001)	return r;
	double mid=(l+r)/2;
	if(f(mid)*f(r)<0)	return search(mid,r);
	else			return search(l,mid);
}
int main(){
	cin>>a>>b>>c>>d;
	for(double i=-100;i<=100;i+=1)
		if(f(i)==0)	printf("%.2lf ",i);
		else if(f(i)*f(i+1)<0)	printf("%.2lf ",search(i,i+1));
	return 0;
}