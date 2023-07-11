#include<bits/stdc++.h>
using namespace std;
int a,b,c;
char ch;
int main(){
	int i;
	cin>>a>>b>>c;
	for(i=1;i<=3;i++){
		cin>>ch;
		switch(ch){
			case 'C':cout<<max(a,max(b,c))<<' ';break;
			case 'B':cout<<a+b+c-max(a,max(b,c))-min(a,min(b,c))<<' ';break;
			case 'A':cout<<min(a,min(b,c))<<' ';break;
		}
	}
	return 0;
} 
