#include<iostream>
using namespace std;
int main(){
	int m,n,i;
	int w[10101]={0};
	int tm,t;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>w[i];
	for(t=m+1,tm=0;t<=n+m;tm++)
		for(i=1;i<=m;i++){
			w[i]--;
			if(w[i]==0){
				w[i]=w[t];
				t++;
			}
		}	
	cout<<tm;
	return 0;
}
