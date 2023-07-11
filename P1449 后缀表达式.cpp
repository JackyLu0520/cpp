#include<bits/stdc++.h>
using namespace std;
string s;
stack<int> stk;
int t=0,a,b;
int main(){
	cin>>s;
	for(int i=0;s[i]!='@';i++){
		if(s[i]>='0'&&s[i]<='9')
			t=t*10+(s[i]-'0');
		else if(s[i]=='.'){
			stk.push(t);
			t=0;
		}
		else{
			b=stk.top();stk.pop();
			a=stk.top();stk.pop();
			if(s[i]=='+')
				stk.push(a+b);
			else if(s[i]=='-')
				stk.push(a-b);
			else if(s[i]=='*')
				stk.push(a*b);
			else if(s[i]=='/')
				stk.push(a/b);
		}
	}
	cout<<stk.top();
	return 0;
}
