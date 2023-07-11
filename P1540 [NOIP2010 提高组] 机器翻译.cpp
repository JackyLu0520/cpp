#include<bits/stdc++.h>
using namespace std;
queue<int> ram;
int m,n,t,cnt=0;
bool f[1010]={0};
int main(){
	int i;
	cin>>m>>n;
	for(i=1;i<=n;i++){
		cin>>t;
		if(!f[t]){
			cnt++;
			f[t]=1;
			ram.push(t);
			if(ram.size()>m){
				f[ram.front()]=0;
				ram.pop();
			}
		}
	}
	cout<<cnt;
	return 0;
}
