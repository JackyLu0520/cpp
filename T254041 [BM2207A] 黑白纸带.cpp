#include<bits/stdc++.h>
using namespace std;
int n,k,w=0,Min=0x7fffffff;
string s;
int main(){
	cin>>n>>k>>s;
	for(int i=0;i<k;i++){
		if(s[i]=='W')	w++;
	}
	for(int i=0;i<n-k+1;i++){
		Min=min(Min,w);
		if(s[i]=='W')	w--;
		if(s[i+k]=='W')	w++;
	}
	cout<<Min;
	return 0;
}