#include<bits/stdc++.h>
using namespace std;
int q;
int main(){
	int i,j,k; 
	cin>>q;
	for(i=1;i<=q;i++){
		int n;
		int pushed[100010],poped[100010];
		stack<int> stk;
		cin>>n;
		for(j=0;j<n;j++)
			cin>>pushed[j];
		for(j=0;j<n;j++)
			cin>>poped[j];
		for(j=0,k=0;j<n||k<n;)
			if(stk.empty()||stk.top()!=poped[k]){
				stk.push(pushed[j]);
				j++;
			}
			else{
				stk.pop();
				k++;
			}
		if(stk.empty())
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
