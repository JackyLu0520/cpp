#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int b[26]={0};
bool isPrime(int n)
{
	int i;
	if(n<2)	return false;
	for(i=3;i*i<=n;i+=2)	if(n%i==0)	return false;
	return true; 
}
int maxn(int n)
{
	return n==0?b[n]:max(maxn(n-1),b[n]); 
}
int min1(int a,int b){
	if(a==0&&b==0)
		return 0;
	else if(a==0)
		return b;
	else if(b==0)
		return a;
	else if(a>b)
		return b;
	else
		return a;
}
int minn(int n)
{
	return n==0?b[n]:min1(minn(n-1),b[n]);
}
int main(){
	int i,t;
	string s;
	cin>>s;
	for(i=0;i<s.size();i++)	b[s[i]-'a']++;
	t=maxn(25)-minn(25);
	if(isPrime(t))
		cout<<"Lucky Word\n"<<t;
	else
		cout<<"No Answer\n"<<0;
	return 0;
} 
