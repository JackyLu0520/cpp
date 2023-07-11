#include<bits/stdc++.h>
using namespace std;
int main(){
	int i,j,k,s=0;
	int n;
	cin>>n;
	n*=18;
	for(i=1,j=1,k=1;i<=n;i++,j++,k++){
		if(j>18)	j=1;
		if(k>27)	k=1;
		if(j==k)	s++;
	}
	cout<<s;
	return 0;
} 
