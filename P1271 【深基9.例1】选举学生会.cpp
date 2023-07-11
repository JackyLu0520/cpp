#include<bits/stdc++.h>
using namespace std;
int main(){
	int i,n,m,b[1000]={0},t;
	cin>>n>>m;
	for(i=1;i<=m;i++){
		cin>>t;
		b[t]++;
	}
	for(i=1;i<=n;i++)
		while(b[i]){
			cout<<i<<' ';
			b[i]--;
		}
	return 0;
}
