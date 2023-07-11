#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,Max=0;
	cin>>n>>m;
	for(int i=n;i<=m;i++){
		int ans=0,t=i;
		for(int j=2;j<=i;j++){
			while(t%j==0){
				t/=j;
				ans++;
			}
			if(t==1)	break;
		}
		Max=max(Max,ans);
	}
	cout<<Max;
	return 0;
}
