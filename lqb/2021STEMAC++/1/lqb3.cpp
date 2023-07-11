#include<bits/stdc++.h>
using namespace std;
bool visited[31]={0};
int num=0;
int main(){
	int i=0,k=0,n,m=3;
	cin>>n;
	while(num<n-1){
		i++;
		if(i>n)	i=1;
		if(!visited[i])	k++;
		if(k==m){
			visited[i]=1;
			num++;
			k=0;
		}
	}
	for(i=1;i<=n;i++)
		if(!visited[i]){
			cout<<i;
			break;
		}
	return 0;
}
