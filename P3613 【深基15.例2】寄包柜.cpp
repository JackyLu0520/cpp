#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > d;
int n,q,a,b,c,t;
int main(){
	int i;
	cin>>n>>q;
	d.resize(n);
	for(i=0;i<q;i++){
		cin>>t>>a>>b;
		if(t==1){
			cin>>c;
			if(d[a].size()<b+1)	d[a].resize(b+1);
			d[a][b]=c;
		}
		else
			cout<<d[a][b]<<endl;
	}
	return 0;
}
