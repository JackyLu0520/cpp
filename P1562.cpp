#include<iostream>
using namespace std;
int n,num=0;
bool col[20]={0},x1[30]={0},x2[30]={0};
char b[20][20];
void Dfs(int m){
	int i,j,k;
	if(m==n){
		num++;
		return;
	}
	for(i=0;i<n;i++){
		if(!col[i]&&!x1[m-i+n]&&!x2[m+i]&&b[m][i]=='*'){
			col[i]=1;
			x1[m-i+n]=1;
			x2[m+i]=1;
			Dfs(m+1);
			col[i]=0;
			x1[m-i+n]=0;
			x2[m+i]=0;
		}
	}
}
int main(){
	int i,j;
	cin>>n;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>b[i][j];
	Dfs(0);
	cout<<num<<endl;
	return 0;
} 
