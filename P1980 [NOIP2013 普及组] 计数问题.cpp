#include<bits/stdc++.h>
using namespace std;
int n,x,s=0;
int main(){
	int i,t;
	cin>>n>>x;
	for(i=1;i<=n;i++){
		t=i;
		while(t!=0){
			if(t%10==x)
				s++;
			t/=10;
		}
	}
	cout<<s;
	return 0;
}
