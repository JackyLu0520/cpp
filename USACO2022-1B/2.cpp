#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k,gf=0,hf=0,cnt=0,gcnt,hcnt;
		string s,ans="";
		cin>>n>>k>>s;
		for(int i=0;i<n;i++)
			ans+='.';
		for(int i=0;i<n;i++){
			if(gf)	gcnt++;
			if(hf)	hcnt++;
			if(gcnt>k)	gf=0;
			if(hcnt>k)	hf=0;
			if(s[i]=='G'&&!gf){
				if(i+k<s.size())	ans[i+k]='G';
				else if(ans[s.size()-1]!='H')	ans[s.size()-1]='G';
				else	ans[s.size()-2]='G';
				gf=1,gcnt=-k,cnt++;
			}
			if(s[i]=='H'&&!hf){
				if(i+k<s.size())	ans[i+k]='H';
				else if(ans[s.size()-1]!='G')	ans[s.size()-1]='H';
				else	ans[s.size()-2]='H';
				hf=1,hcnt=-k,cnt++;
			}
		}
		cout<<cnt<<endl;
		cout<<ans<<endl;
	}
	return 0;
}