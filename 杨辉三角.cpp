#include<iostream>
using namespace std;
int main(){
	int t[20][20]={{0}},n,i,j;
	cin>>n;
	t[0][0]=1;
	for(i=1;i<n;i++){
		t[i][0]=1;
		t[i][i]=1;
		for(j=1;j<=i;j++)
			t[i][j]=t[i-1][j]+t[i-1][j-1];
	}
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++)
			cout<<t[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}
