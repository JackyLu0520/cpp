#include<bits/stdc++.h>
using namespace std;
int main(){
	int l,r,s;
	while(scanf("%d%d%d",&l,&r,&s)!=EOF){
		if(s<l)				cout<<"N0"<<endl;
		else if(s>=l&&s<=r)	cout<<"YE5"<<endl;
		else{
			if(s%(l+r)==0||s%(l+r)<l)	cout<<"N0"<<endl;
			else			cout<<"YE5"<<endl;
		}
	}
	return 0;
}
