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
	while(m--){
		int op;
		cin>>op;
		if(op==1){
			int x,y;
			cin>>x>>y;
			add(x,1);
			add(y+1,-1);
		}
		else{
			int x;
			cin>>x;
			cout<<getsum(x)%2<<endl;
		}
	}
	return 0;
}
