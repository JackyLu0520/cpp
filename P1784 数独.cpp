#include<iostream>
using namespace std;
int x[81],y[81],k;
bool row[9][10]={0},col[9][10]={0},box[3][3][10]={0};
int b[9][9];
void Dfs(int n){
	int i,j;
	if(n==k){
		for(i=0;i<9;i++){
			for(j=0;j<9;j++)
				cout<<b[i][j]<<' ';
			cout<<endl;
		}	
		return;
	}
	for(i=1;i<=9;i++){
		if(!row[x[n]][i]&&!col[y[n]][i]&&!box[x[n]/3][y[n]/3][i]){
			b[x[n]][y[n]]=i;
			row[x[n]][i]=col[y[n]][i]=box[x[n]/3][y[n]/3][i]=1;
			Dfs(n+1);
			row[x[n]][i]=col[y[n]][i]=box[x[n]/3][y[n]/3][i]=0;
		}
	}
}
int main(){
	int i,j;
	for(i=0,k=0;i<9;i++)
		for(j=0;j<9;j++){
			cin>>b[i][j];
			if(b[i][j]){
				row[i][b[i][j]]=1;
				col[j][b[i][j]]=1;
				box[i/3][j/3][b[i][j]]=1;
			}
			else{
				x[k]=i;
				y[k]=j;
				k++;
			}
		}
	Dfs(0);
	return 0;
} 
