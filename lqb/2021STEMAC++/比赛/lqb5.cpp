#include<bits/stdc++.h>
using namespace std;
bool b[(1<<27)-1]={0};
int s,f,Min=0x7fffffff,n;
void Dfs(int step,int m){
	if(m==f){
		Min=min(Min,step);
	}
	for(int i=0;i<n;i++){
		if(!b[m]){
			b[m]=1;
			if(i==0)
				Dfs(step+1,m^(1<<i)^(1<<(i+1)));
			else if(i==n-1)
				Dfs(step+1,m^(1<<i)^(1<<(i-1)));
			else
				Dfs(step+1,m^(1<<i)^(1<<(i-1))^(1<<(i+1)));
			b[m]=0;
		}
	}
}
int main(){
	string s1,s2;
	cin>>s1>>s2;
	n=s1.size();
	for(int i=0;i<n;i++){
		s=(s<<1)+int(s1[i]-'0');
		f=(f<<1)+int(s2[i]-'0');
	}
	Dfs(0,s);
	cout<<Min;
	return 0;
}
