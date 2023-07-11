#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
	cin>>n;
	getchar();
	for(int i=0;i<n;i++){
		char c=getchar();
		getchar();
		s.append(1,c);
	}
	sort(s.begin(),s.end());
	cout<<s;
	return 0;
}