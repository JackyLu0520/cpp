#include<bits/stdc++.h>
using namespace std;
bool visited[31]={0};
int num=0;
int main(){
	int i=0,k=0,n,m=2,sn;
	cin>>n;
	sn=n;
	while(1){
		fill(visited,visited+n,0); 
		while(num<n){
			i++;
			if(i>n)	i=1;
			if(!visited[i])	k++;
			if(k==m){
				visited[i]=1;
				num++;
				k=0;
				cout<<i<<' ';
			}
		}
		if(i==n)	break;
		n=i;
	}
	cout<<sn+n;
	return 0;
}
