#include<bits/stdc++.h>
using namespace std;
int main(){
	stack<int> stk;
	for(int i=0;i<10;i++){
		stk.push(i);
		cout<<i<<' ';
	}
	cout<<endl;
	while(!stk.empty()){
		cout<<stk.top()<<' ';
		stk.pop();
	}
	return 0;
}
