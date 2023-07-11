#include<iostream>
using namespace std;
bool b[11]={0};
int a[11],n=9,num=0;
void DFS(int step){
	int i; 
	if(step>n&&100*a[1]+10*a[2]+a[3]+100*a[4]+10*a[5]+a[6]==100*a[7]+10*a[8]+a[9]){
		cout<<a[1]<<a[2]<<a[3]<<'+'<<a[4]<<a[5]<<a[6]<<'='<<a[7]<<a[8]<<a[9]<<endl;
		num++;
		return;
	}
	for(i=1;i<=n;i++)
		if(!b[i]){
			a[step]=i;
			b[i]=1;
			DFS(step+1);
			b[i]=0; 
		}
}
int main(){
	DFS(1);
	cout<<num/2;
	return 0;
}
