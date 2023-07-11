#include<bits/stdc++.h>
using namespace std;
string n;
int Max=0,x;
int main(){
	cin>>n;
	for(int i=0;i<n.size();i++)
		if(n[i]-'0'+n[i+1]-'0'>Max){
			Max=n[i]-'0'+n[i+1]-'0';
			x=i;
			if((n[i]-'0'+n[i+1]-'0')/10>0)	break;
		}
	cout<<n.substr(0,x)<<Max<<n.substr(x+2,n.size()-x-1);
	return 0;
}