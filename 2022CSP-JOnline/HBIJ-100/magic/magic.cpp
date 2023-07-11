#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	string a,b;
	int k,i;
	cin>>a>>b>>k;
	if(a==b){
		cout<<0;
		return 0;
	}
	for(i=0;a[i]==b[i];i++);
	int ans=a.size()-i;
	for(i=i+1;i<a.size();i++)
		if(b[i]=='0')	ans+=1;
		else		ans+=2;
	cout<<ans*k;
	return 0;
}