#include<bits/stdc++.h>
using namespace std;
string s;
bool isy[26]={0};
long long cnt;
void dfs(int step,int y,int f,string s1,long long res){
	if(y==3||f==3){
		return;
	}
	if(step==s.size()){
		if(s1.find('L')!=string::npos)
			cnt+=res;
		return;
	}
	if(s[step]=='_'){
		dfs(step+1,y+1,0,s1+'A',res*5);
		dfs(step+1,0,f+1,s1+'B',res*20);
		dfs(step+1,0,f+1,s1+'L',res);
	}else{
		if(isy[s[step]-'A'])
			dfs(step+1,y+1,0,s1+s[step],res);
		else
			dfs(step+1,0,f+1,s1+s[step],res);
	}
}
int main(){
	cin>>s;
	isy['A'-'A']=1;
	isy['E'-'A']=1;
	isy['I'-'A']=1;
	isy['O'-'A']=1;
	isy['U'-'A']=1;
	dfs(0,0,0,"",1);
	cout<<cnt;
	return 0;
}