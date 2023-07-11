#include<iostream>
using namespace std;
bool Joseph(int m,int k){
	bool a[28]={0};
	int i,j,num;
	for(i=1,j=num=0;num<k;i++){
		if(i>2*k)	i=1;
		if(!a[i])	j++;
		if(j==m){
			if(i<=k)	return 1;
			a[i]=1;
			j=0;
			num++;
		}
	}
	return 0;
}
int main(){
	int k,m;
	cout<<"int ans[14]={";
	for(k=1;k<=13;k++){
		for(m=k+1;Joseph(m,k);m++)	;
		cout<<m<<',';
	}
	cout<<"\b};";
	return 0;
}
