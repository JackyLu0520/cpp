#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	cin>>t;
	while(t--){
		long long n,x,y;
		cin>>n;
		/*for(x=0;x<=n/4;x++){
			y=n-4*x;
			if(y%6==0){
				cout<<x+y/6<<' ';
				break;
			}
		}
		if(x==n/4){
			cout<<-1<<endl;
			continue;
		}
		for(x=n/4;x>=0;x--){
			y=n-4*x;
			if(y%6==0){
				cout<<x+y/6<<endl;
				break;
			}
		}*/
		if(n==2||n%2!=0)	cout<<-1<<endl;
		else	cout<<(long long)ceil(n/(long double)6.0)<<' '<<n/4<<endl;
	} 
	return 0;
}