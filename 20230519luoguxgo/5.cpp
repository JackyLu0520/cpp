#include<bits/stdc++.h>
using namespace std;
int p[2010],n;
void shift(){
	for(int i=n;i>=0;i--)
		p[i+1]=p[i];
	p[1]=p[n+1];
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	while(1){
		shift();
		for(int i=1;i<=n;i++)
			cout<<p[i]<<' ';
		cout<<endl;
		if(p[n]==n)	break;
	}
	return 0;
}
