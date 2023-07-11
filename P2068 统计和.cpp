#include<bits/stdc++.h>
using namespace std;
long long n,m,c[500010];
long long lowbit(int x){
	return x&(-x);
}
long long getsum(int x){
	long long t=0;
	while(x){
		t+=c[x];
		x-=lowbit(x);
	}
	return t;
}
void add(int x,int d){
	while(x<=n){
		c[x]+=d;
		x+=lowbit(x);
	}
}
int main(){
	cin>>n>>m;
	while(m--){
		char op;
		int x,y;
		cin>>op>>x>>y;
		getchar();
		if(op=='x')	add(x,y);
		else		cout<<getsum(y)-getsum(x-1)<<endl;
	}
	return 0;
}
