#include<bits/stdc++.h>
using namespace std;
int n,k,x[25],cnt;
bool isPrime(int a){
	int i;
	if(a==1)	return 0;
	for(i=2;i*i<=a;i++)
		if(a%i==0)
			return 0;
	return 1;
}
void Dfs(int s,int num,int step){
	if(step>n||num==k){
		if(num==k)
			cnt+=isPrime(s);
		return;
	}
	Dfs(s+x[step],num+1,step+1);
	Dfs(s,num,step+1);
}
int main(){
	int i;
	cin>>n>>k;
	for(i=1;i<=n;i++)
		cin>>x[i];
	Dfs(0,0,1);
	cout<<cnt;
	return 0;
}
