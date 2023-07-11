#include<bits/stdc++.h>
using namespace std;
int n,m,s,p;
bool a;
struct toy{
	bool f;
	string name;
}toys[100001];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>toys[i].f>>toys[i].name;
	p=1;
	for(int i=1;i<=m;i++){
		cin>>a>>s;
		s%=n;
		if(a==toys[p].f){
			p-=s;
			if(p<=0)	p+=n;
		}
		else{
			p+=s;
			if(p>n)	p-=n;
		}
	}
	cout<<toys[p].name;
	return 0;
}
