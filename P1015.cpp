#include<iostream>
#include<string>
using namespace std;
string ms;
int n,m[101],m1[101];
void get(){
	int i;
	cin>>n>>ms;
	m[0]=ms.size();
	for(i=0;i<m[0];i++)
		if(ms[i]<='9')	m[m[0]-i]=ms[i]-'0';
		else			m[m[0]-i]=ms[i]-'A'+10;
}
bool isPalindrome(){
	for(int i=1;i<=m[0]/2;i++)
		if(m[i]!=m[m[0]-i+1])
			return 0;
	return 1;
}
void add(){
	int i,x=0;
	for(i=1;i<=m[0];i++)	m1[m[0]-i+1]=m[i];
	for(i=1;i<=m[0];i++){
		m[i]+=m1[i]+x;
		x=m[i]/n;
		m[i]%=n;
	}
	m[i]=x;
	if(m[i]==0)	m[0]=i-1;
	else		m[0]=i;
}
int main(){
	int i=0,step;
	get();
	if(isPalindrome())	step=0;
	else
		for(i=1;i<=30;i++){
			add();
				step=i;
			if(isPalindrome())	{
				break;
			}
		}
	if(i==31)	cout<<"Impossible!";
	else		cout<<"STEP="<<step;
	return 0;
}
