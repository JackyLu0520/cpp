#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=1;n>=i;i++){
		n-=i;
		cout<<i<<endl;
	}
	return 0;
}
