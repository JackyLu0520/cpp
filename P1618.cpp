#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int n1,n2,n3;
bool b[10]={0};
void Dfs(int step){
	if(step==9){
		if(n1*1.0/a==n2*1.0/b&&n2*1.0/b==n3*1.0/c){
			cout<<n1<<n2<<n3;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			
		}
	}
}
int main(){
	
}