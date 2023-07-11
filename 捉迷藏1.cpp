#include<bits/stdc++.h>
using namespace std;
bool visited[10]={0};
int main(){
	int i,n=9;
	for(i=1;i<=1000;i++){
		n=(n+i)%10;
		visited[n]=1;
	}
	for(i=0;i<10;i++)
		if(!visited[i])
			cout<<i+1<<' ';
	return 0;
} 
