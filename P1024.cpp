#include<cstdio>
using namespace std;
double a,b,c,d;
double f(int x){
	return a*x*x*x+b*x*x+c*x+d;
}
double search(int l,int r){
	double mid;
	mid=(l+r)/2;
	if(r-l<=0.001)	return l;
	if(f(mid)*f(r)<0)	return search(mid,r);
	else	return search(l,mid);
}
int main(){
	int i,s=0;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for(i=-100;i<100;i++){
		if(f(i)==0){
			printf("%.2lf",double(i));
			s++;
		}
		if(f(i)*f(i+1)<=0){
			printf("%.2lf",search(i,i+1));
			s++;
		}
		if(s==3)	break;
	}
	return 0;
}
