#include<bits/stdc++.h>
using namespace std;
bool b[15]={0};
int a[15],n;
void Dfs(int step){
	int i;
	if(step>n){
		for(i=1;i<=n;i++)	cout<<setw(5)<<a[i];
		cout<<endl;
		return;
	}
	for(i=1;i<=n;i++)
		if(!b[i]){
			a[step]=i;
			b[i]=1;
			Dfs(step+1);
			b[i]=0;
		}
}
int main(){
	cin>>n;
	Dfs(1);
	return 0;
} 
