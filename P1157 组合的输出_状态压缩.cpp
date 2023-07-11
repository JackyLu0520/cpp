#include<bits/stdc++.h>
using namespace std;
int n,r;
int main(){
	cin>>n>>r;
	for(int m=0;m<(1<<n);m++){
		int p=0,t[21];
		for(int i=0;i<n;i++)
			if(m&(1<<i))
				t[p++]=i+1;
		if(p==r){
			for(int i=0;i<r;i++)
				cout<<setw(3)<<t[i];
			cout<<endl;
		}
	}
}
