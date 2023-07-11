#include<bits/stdc++.h>
using namespace std;
int n,x,k;
int main(){
	cin>>n;
	for(k=1;;k++){
		x=n-1092*k;
		if(x%364==0&&x<=36400){
			cout<<x/364<<endl<<k;
			break;
		}
	}
	return 0;
}