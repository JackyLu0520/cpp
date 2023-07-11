#include<bits/stdc++.h>
using namespace std;
int n,m,c[500010];
int lowbit(int x){
	return x&(-x);
}
int getsum(int x){
	int t=0;
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
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		add(i,x);
	}
	while(m--){
		int op,x,y;
		cin>>op>>x>>y;
		if(op==1)	add(x,y);
		else		cout<<getsum(y)-getsum(x-1)<<endl;
	}
	return 0;
}
