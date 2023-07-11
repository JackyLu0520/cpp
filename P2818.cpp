#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	int m[1010]={0},n,x,i,ms;
	cin>>n>>s;
	ms=s.size();
	for(i=0;i<ms;i++)	m[ms-i]=s[i]-'0';
	for(i=ms,x=0;i>=1;i--){
		x=(x*10+m[i])%n;
	}
	if(x==0)	cout<<n;
	else		cout<<x;
	return 0;
}
