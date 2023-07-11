#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
const double EPS=0.0001;
int n;
double p,sum,a[MAXN],b[MAXN];
bool check(double x){
	double tot=p*x;
	double cnt=0;
	for(int i=1;i<=n;i++){
		double t=a[i]*x;
		if(t<=b[i])	continue;
		cnt+=t-b[i];
	}
	return cnt<=tot;
}
int main(){
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		sum+=a[i];
	}
	if(sum<=p){
		cout<<-1;
		return 0;
	}
	double l=0,r=1e10,ans;
	while(r-l>EPS){
		double mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid;
		}else
			r=mid;
	}
	cout<<ans;
	return 0;
}