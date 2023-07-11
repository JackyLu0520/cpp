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
	int x=0,y;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		y=x;
		cin>>x;
		add(i,x-y);
	}
	while(m--){
		int op;
		cin>>op;
		if(op==1){
			int x,y,k;
			cin>>x>>y>>k;
			add(x,k);
			add(y+1,-k);
		}
		else{
			int x;
			cin>>x;
			cout<<getsum(x)<<endl;
		}
	}
	return 0;
}
