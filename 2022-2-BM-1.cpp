#include<bits/stdc++.h>
using namespace std;
int num[26]={0,0,100,500,0,0,0,0,1,0,0,50,1000,0,0,0,0,0,0,0,0,5,0,10,0,0};
int t,n;
string s;
int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>s;
		n=0;
		for(int i=0;i<s.size();){
			if(s[i]=='I'&&(s[i+1]=='V'||s[i+1]=='X'))
				n+=num[s[i+1]-'A']-num[s[i]-'A'];
			else if(s[i]=='X'&&(s[i+1]=='L'||s[i+1]=='C'))
				n+=num[s[i+1]-'A']-num[s[i]-'A'];
			else if(s[i]=='C'&&(s[i+1]=='D'||s[i+1]=='M'))
				n+=num[s[i+1]-'A']-num[s[i]-'A'];
			else	{i++;continue;}
			s.erase(i,2);
		}
		//cout<<s<<endl;
		for(int i=0;i<s.size();i++)
			n+=num[s[i]-'A'];
		cout<<n<<endl;
	}
	return 0;
}