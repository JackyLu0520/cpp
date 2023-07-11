#include<bits/stdc++.h>
using namespace std;
bool M[1010];
string IP[1010];
int n;
bool isIPOK(string IP){
	int m[5],dot=0,colon=0;
	for(int i=0;i<IP.size();i++){
		if(IP[i]=='.')	dot++;
		if(IP[i]==':')	colon++;
	}
	if(dot!=3||colon!=1)	return 0;
	for(int i=0,j=1;i<IP.size();i++)
		if(IP[i]=='.'||IP[i]==':')
			m[j++]=i;
	if(IP[m[4]]!=':')	return 0;
	if(m[1]==0||m[1]+1==m[2]||m[2]+1==m[3]
	||m[3]+1==m[4]||m[4]==IP.size()-1)
		return 0;
	if(IP[0]=='0'&&m[1]>1
	||IP[m[1]+1]=='0'&&m[1]+2<m[2]
	||IP[m[2]+1]=='0'&&m[2]+2<m[3]
	||IP[m[3]+1]=='0'&&m[3]+2<m[4]
	||IP[m[4]+1]=='0'&&m[4]+2<IP.size())
		return 0;
	long long a,b,c,d,e;
	sscanf(IP.c_str(),
	"%lld.%lld.%lld.%lld:%lld",
	&a,&b,&c,&d,&e);
	if(a>255||b>255||c>255||d>255||e>65535)
		return 0;
	return 1;
}
int main(){
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++){
		string t;
		cin>>t;
		if(t=="Server")	M[i]=0;
		else			M[i]=1;
		cin>>IP[i];
		if(!isIPOK(IP[i]))	cout<<"ERR"<<endl;
		else if(M[i]==0){
			for(j=1;j<i;j++)
				if(M[j]==0&&IP[i]==IP[j]){
					cout<<"FAIL"<<endl;
					break;
				}
			if(j==i)	cout<<"OK"<<endl;
		}
		else if(M[i]==1){
			for(j=1;j<i;j++)
				if(M[j]==0&&IP[i]==IP[j]){
					cout<<j<<endl;
					break;
				}
			if(j==i)	cout<<"FAIL"<<endl;
		}
	}
	return 0;
}
