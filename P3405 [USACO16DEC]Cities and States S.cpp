#include<bits/stdc++.h>
using namespace std;
int n,ans,a[676][676];
int Hash(string s){
	return (s[0]-'A')*26+(s[1]-'A');
}
int main(){
	cin>>n;
	while(n--){
		string s1,s2;
		cin>>s1>>s2;
		int h1=Hash(s1),h2=Hash(s2);
		if(h1!=h2){
			a[h1][h2]++;
			ans+=a[h2][h1];
		}
	}
	cout<<ans;
	return 0;
}