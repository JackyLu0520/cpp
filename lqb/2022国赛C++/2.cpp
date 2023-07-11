#include<bits/stdc++.h>
using namespace std;
bool visited[210]={0};
int num=0;
int main(){
	int i=0,k=0,x,y,m;
	cin>>x>>y>>m;
	while(num<y){
		i++;
		if(i>x+y)	i=1;
		if(!visited[i])	k++;
		if(k==m){
			visited[i]=1;
			num++;
			k=0;
		}
	}
	for(i=1;i<=x+y;i++)
		if(!visited[i])
			cout<<i<<' ';
	return 0;
}
