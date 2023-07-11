#include<bits/stdc++.h>
using namespace std;
string s;
int t=0,n,q,p;
bool a,b,x[100010];
int main(){
	getline(cin,s);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	cin>>q;
	for(int j=0;j<q;j++){
		cin>>p;
		stack<bool> stk;
		x[p]=!x[p];
		for(int i=0;i<s.size();i++){
			if(s[i]>='0'&&s[i]<='9')
				t=t*10+(s[i]-'0');
			else if(s[i]==' '&&s[i-1]>='0'&&s[i-1]<='9'){
				stk.push(x[t]);
				t=0;
			}
			else if(s[i]=='&'){
				b=stk.top();stk.pop();
				a=stk.top();stk.pop();
				stk.push(a&&b);
			}
			else if(s[i]=='|'){
				b=stk.top();stk.pop();
				a=stk.top();stk.pop();
				stk.push(a||b);
			}
			else if(s[i]=='!'){
				a=stk.top();stk.pop();
				stk.push(!a);
			}
		}
		cout<<stk.top()<<endl;
		x[p]=!x[p];
	}
	return 0;
}
