#include<bits/stdc++.h>
using namespace std;
int b[26],Min=100,Max=0;
bool isPrime(int n){
	if(n<=1)	return 0;
	for(int i=2;i*i<=n;i++)
		if(n%i==0)
			return 0;
	return 1;
}
int main(){
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		b[s[i]-'a']++;
	for(int i=0;i<26;i++){
		if(b[i]>Max)
			Max=b[i];
		if(b[i]<Min&&b[i]!=0)
			Min=b[i];
	}
	if(isPrime(Max-Min))
		cout<<"Lucky Word"<<endl<<Max-Min;
	else
		cout<<"No Answer"<<endl<<0;
	return 0;
}
