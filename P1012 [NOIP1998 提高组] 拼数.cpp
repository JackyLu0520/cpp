#include<bits/stdc++.h>
using namespace std;
int n;
string num[20];
bool cmp(string a,string b){
	return a+b>b+a;
}
int main(){
	int i;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>num[i];
	sort(num,num+n,cmp);
	for(i=0;i<n;i++)
		cout<<num[i];
	return 0;
}
