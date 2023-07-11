#include<bits/stdc++.h>
using namespace std;
char a[5][5];
int main(){
	memset(a,'*',sizeof(a));
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++)
			cout<<a[i][j];
		cout<<endl;
	}
	return 0;
}
