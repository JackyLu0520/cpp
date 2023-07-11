#include<iostream>
using namespace std;
bool b[11]={0};
int a[11],n;
void DFS(int step){
	int i; 
	if(step>n){
		for(i=1;i<=n;i++)	cout<<a[i];
		cout<<endl;
		return;
	}
	for(i=1;i<=n;i++)
		if(!b[i]){
			a[step]=i;
			b[i]=1;
			DFS(step+1);
			b[i]=0; 
		}
}
int main(){
	cin>>n;
	DFS(1);
	return 0;
}
