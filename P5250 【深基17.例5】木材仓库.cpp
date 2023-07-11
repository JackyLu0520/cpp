#include<bits/stdc++.h>
using namespace std;
set<int> s;
const int inf=2147483647;
int q;
int main(){
	cin>>q;
	while(q--){
		int opt,len;
		cin>>opt>>len;
		if(opt==1)
			if(s.count(len))	cout<<"Already Exist"<<endl;
			else				s.insert(len);
		else{
			if(!s.size())
				cout<<"Empty"<<endl;
			else if(s.count(len)){
				cout<<len<<endl;
				s.erase(len);
			}else{
				auto it1=s.lower_bound(len);
				auto it2=s.upper_bound(len);
				int len1=(it1==s.begin())?inf:*(--it1);
				int len2=(it2==s.end())?inf:*it2;
				int res;
				if(abs(len-len1)<abs(len-len2))
					res=len1;
				else if(abs(len-len1)>abs(len-len2))
					res=len2;
				else
					res=min(len1,len2);
				cout<<res<<endl;
				s.erase(res);
			}
		}
	}
	return 0;
}