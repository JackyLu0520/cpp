#include<bits/stdc++.h>
using namespace std;
int n,m=0;
string num[20];
bool cmp(string a,string b){
	if(a.size()>b.size())	return true;
	else if(a.size()<b.size())	return false;
	for(int i=0;i<a.size();i++)
		if(a[i]>b[i])
			return true;
		else if(a[i]<b[i])
			return false;
	return false;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>num[i];
	for(int i=0;i<n;i++)
		if(cmp(num[i],num[m]))
			m=i;
	cout<<m+1<<endl<<num[m];
	return 0;
}
