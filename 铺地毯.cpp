#include<iostream>
using namespace std;
int n,x,y,a[100001],b[100001],g[100001],k[100001],i;
int main(){
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i]>>b[i]>>g[i]>>k[i];
	cin>>x>>y;
	for(i=n;i>=1;i--)
		if(x>=a[i]&&x<=a[i]+g[i]&&y>=b[i]&&y<=b[i]+k[i]){
			cout<<i;
			return 0;
		}
	cout<<-1;
	return 0;	
}
