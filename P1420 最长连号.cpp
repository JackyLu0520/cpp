#include<bits/stdc++.h>
using namespace std;
int s,a,pre=-1,n,Max=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a-pre==1)
			s++;
		else{
			Max=max(Max,s);
			s=1;
		}
		pre=a;
	}
	cout<<Max;
	return 0;
} 
