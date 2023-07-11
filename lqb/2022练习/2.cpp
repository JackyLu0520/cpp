#include<bits/stdc++.h>
using namespace std;
int main(){
	string a;
	int cnt=0;
	cin>>a;
	for(int i=0;i<a.size();i++)
		if(a[i]>='0'&&a[i]<='9')
			cnt++;
	cout<<cnt;
	return 0;
}
