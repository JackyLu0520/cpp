#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,cnt=0;
	cin>>n;
	for(int i=1;;i++){
		if(i%2==0)
			for(int j=1;j<=i;j++){
				cnt++;
				if(cnt==n){
					cout<<j<<'/'<<(i-j+1);
					return 0;
				}
			}
		else
			for(int j=i;j>=1;j--){
				cnt++;
				if(cnt==n){
					cout<<j<<'/'<<(i-j+1);
					return 0;
				}
			}
	}
	return 0;
}