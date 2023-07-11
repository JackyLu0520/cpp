#include<bits/stdc++.h>
using namespace std;
int k;
double s=0;
int main(){
	int i;
	cin>>k;
	for(i=1;s<=k;i++)	s+=1.0/i;
	cout<<i-1;
	return 0;
} 
