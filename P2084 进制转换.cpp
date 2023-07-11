#include<bits/stdc++.h>
using namespace std;
int m,a[1010],lena;
string n;
int main(){
	int i;
	cin>>m>>n;
	lena=n.size();
	for(i=0;i<lena;i++)
		if(n[i]!='0'){
			if(i!=0)
				cout<<'+';
			cout<<n[i]<<"*"<<m<<"^"<<lena-i-1;
		}
	return 0;
}
