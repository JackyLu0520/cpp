#include<bits/stdc++.h>
using namespace std;
bool visited[31]={0};
int num=0;
int main(){
	int i=0,k=0;
	while(num<15){
		i++;
		if(i>30)	i=1;
		if(!visited[i])	k++;
		if(k==9){
			visited[i]=1;
			num++;
			k=0;
		}
	}
	for(i=1;i<=30;i++)
		if(!visited[i])
			cout<<i<<' ';
	return 0;
}
