#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=n;i>=0;i--){
		int t;
		cin>>t;
		if(t==0)	continue;
		if(i!=n&&t>0&&n!=1)	cout<<'+';
		else if(t<0)	cout<<'-';
		if(i==0)	{cout<<abs(t);continue;}
		if(t!=1&&t!=-1)	cout<<abs(t);
		if(i==1)	cout<<"x";
		else		cout<<"x^"<<i;
	}
	return 0;
}