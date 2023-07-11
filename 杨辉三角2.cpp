#include<bits/stdc++.h>
using namespace std;
int t[11][11];
int main(){
	for(int i=1;i<=10;i++){
		t[i][1]=t[i][i]=1;
		for(int j=2;j<i;j++)
			t[i][j]=t[i-1][j-1]+t[i-1][j];
	}
	for(int i=1;i<=10;i++){
		for(int j=1;j<=10-i;j++)
			cout<<"  "; 
		for(int j=1;j<=i;j++)
			cout<<setw(4)<<t[i][j];
		cout<<endl;
	}
	return 0;
} 
