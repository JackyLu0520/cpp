#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	unsigned long long k,t,m,x=1,l1=0,l2=0,l12=0;
	cin>>k>>t>>m;
	for(int i=1;i<=k;i++){
		bool f1=0,f2=0;
		unsigned long long x1=x;
		if(x1==0)	f2=1;
		while(x1){
			if(x1%10==1)	f1=1;
			if(x1%10==0)	f2=1;
			x1/=10;
		}
		if(f1)	l1++;
		if(f2)	l2++;
		if(f1&&f2)	l12++;
		//cout<<x<<' '<<f1<<' '<<f2<<endl;
		x=(x+t)%m;
	}
	cout<<l1-l12<<' '<<l2-l12<<' '<<l12;
	return 0;
}
