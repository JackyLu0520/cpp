#include<bits/stdc++.h>
using namespace std;
int n;
struct B{
	int s,c;
	B(){}
	B(int S,int C){
		s=S;
		c=C;
	}
};
vector<B> t[100010];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int f,s,c;
		scanf("%d%d%d",&f,&s,&c);
		t[f].push_back(B(s,c));
	}

}
