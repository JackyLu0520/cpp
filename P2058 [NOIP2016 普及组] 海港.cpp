#include<bits/stdc++.h>
using namespace std;
struct boat{
	int t,k;
}in;
queue<boat> boats;
queue<int> x;
int nation[100010]={0},n,cnt,t;
int main(){
	int i,j,l,m;
	cin>>n;
	for(i=1,j=1;i<=n;i++){
		cin>>in.t>>in.k;
		for(m=1;m<=in.k;m++){
			cin>>t;
			nation[t]++;
			if(nation[t]==1)	cnt++;
			x.push(t);
		}
		boats.push(in);
		while(j<=n&&(boats.front().t+86400)<=boats.back().t){
			for(l=1;l<=boats.front().k;l++){
				nation[x.front()]--;
				if(!nation[x.front()])	cnt--;
				x.pop();
			}
			boats.pop();
		}
		cout<<cnt<<endl;
	}
	return 0;
}
