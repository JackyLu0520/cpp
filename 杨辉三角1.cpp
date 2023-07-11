#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int t[31][31],i,j;
	for(i=1;i<=30;i++){
		t[i][1]=t[i][i]=1;
		for(j=2;j<i;j++)
			t[i][j]=t[i-1][j]+t[i-1][j-1];
	}
	for(i=1;i<=30;i++){
		cout<<setw((30-i)*4.5+1);
		for(j=1;j<=i;j++)
			cout<<t[i][j]<<setw(9);
		cout<<endl<<endl;
	}
}
