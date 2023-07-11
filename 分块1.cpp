#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
int n,a[50010],add[260],s;
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	s=int(sqrt(n));
	for(int i=1;i<=n;i++){
		int opt,l,r,c;
		cin>>opt>>l>>r>>c;
		if(opt==0){
			if(r-l<s){
				for(int i=l;i<=r;i++)	a[i]+=c;
				continue;
			}
			for(int i=l;i<=((l-1)/s+1)*s;i++)	a[i]+=c;
			for(int i=r/s*s+1;i<=r;i++)	a[i]+=c;
			for(int i=(l-1)/s+2;i<=r/s;i++)	add[i]+=c;
		}else{
			cout<<a[r]+add[(r-1)/s+1]<<endl;
		}
	}
	return 0;
}
/*
Sample:
4
1 2 2 3
0 1 3 1
1 0 1 0
0 1 2 2
1 0 2 0

2
5
*/
