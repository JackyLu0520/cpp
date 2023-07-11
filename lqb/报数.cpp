#include<bits/stdc++.h>
using namespace std;
int n,num=0;
bool flag[600]={0};
int main(){
	int i=0,k=0;
	cin>>n;
	while(n>num){
		i++;
		if(i>n)	i=1;
		if(!flag[i])	k++;
		if(k==3){
			flag[i]=1;
			k=0;
			num++;
		}
	}
	cout<<i;
	return 0;
}
