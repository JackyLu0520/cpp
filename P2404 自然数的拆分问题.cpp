#include<iostream>
using namespace std;
int a[9]={0},p=0,n;
void Dfs(int m){
	if(m==0){
		if(p!=1)
			for(int i=0;i<p;i++)
				if(i<p-1)
					cout<<a[i]<<'+';
				else
					cout<<a[i]<<endl;
		return;
	}
	for(int i=1;i<=m;i++)
		if(i>=a[p-1]){
			a[p++]=i;
			Dfs(m-i);
			a[p]=0;
			p--;
			if(m-i==0)
				break;
		}
}
int main(){
	cin>>n;
	Dfs(n);
	return 0;
}
