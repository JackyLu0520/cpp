#include<bits/stdc++.h>
using namespace std;
int n,m,Max=0;
int v[25],w[25];
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++)
		cin>>v[i]>>w[i];
	for(int mask=0;mask<(1<<m);mask++){
		int sv=0,s=0;
		for(int i=0;i<m;i++)
			if(mask&(1<<i)){
				sv+=v[i];
				s+=v[i]*w[i];
			}
		if(sv<=n)	Max=max(Max,s);
	}
	cout<<Max;
	return 0;
}