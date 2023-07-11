#include<bits/stdc++.h>
using namespace std;
int main(){
	int i,j,k,s=0;
	for(i=1,j=1,k=1;i<=1000;i++,j++,k++){
		if(j>20)	j=1;
		if(k>30)	k=1;
		if(j==k)	s++;
	}
	cout<<s;
	return 0;
} 
