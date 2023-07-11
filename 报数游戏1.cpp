#include<iostream>
using namespace std;
int i,n=0,g=0,cnt=0;
int main(){
	for(i=1;i<=1000;i++){
		n++;g++;
		if(n>20)	n=1;
		if(g>30)	g=1;
		if(n==g)	cnt++;
	}
	cout<<cnt;
	return 0;
}
