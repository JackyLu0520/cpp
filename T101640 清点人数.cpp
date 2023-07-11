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
		char op;
		cin>>op;
		if(op=='A'){
			int x;
			cin>>x;
			cout<<getsum(x)<<endl;
		}else if(op=='B'){
			int x,y;
			cin>>x>>y;
			add(x,y);
		}else{
			int x,y;
			cin>>x>>y;
			add(x,-y);
		}
	}
	return 0;
}
