#include<bits/stdc++.h>
using namespace std;
int prior(char x){
    if(x=='(')	return 0;
    if(x=='+'||x=='-')	return 1;
    if(x=='*'||x=='/')	return 2;
}
int main(){
    stack<char> s;
    freopen("calc.in","r",stdin);
    freopen("calc.out","w",stdout);
    while(!cin.eof()){
	string t;
	cin>>t;
        if(t[0]>='0'&&t[0]<='9')
            cout<<t;
        if(t[0]=='(')  s.push('(');
        if(t[0]==')'){
            while(!s.empty()&&s.top()!='('){
                cout<<s.top();
                s.pop();
            }
            if(!s.empty())
                s.pop();
        }
        if(t[0]=='+'||t[0]=='-'||t[0]=='*'||t[0]=='/'){
            while(!s.empty()&&prior(s.top())>=prior(t[0])){
                cout<<s.top();
                s.pop();
            }
            s.push(t[0]);
        }
    }
    while(!s.empty()){
    	cout<<s.top();
	s.pop();
    }
    return 0;
}
