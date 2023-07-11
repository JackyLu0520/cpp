#include<iostream>
#include<string>
using namespace std;
int main(){
	string ISBN;
	int isbn[10],n=0,i,j;
	cin>>ISBN;
	for(i=0,j=0;i<10;i++,j++){
		if(ISBN[j]!='-')	isbn[i]=int(ISBN[j]-'0');
		else		i--;
	}
	if(isbn[9]==40)
		isbn[9]=10;
	for(i=0;i<9;i++)
		n+=isbn[i]*(i+1);
	n%=11;
	if(n==isbn[9])
		cout<<"Right";
	else{
		ISBN[12]=char(n+'0');
		if(ISBN[12]==':')
			ISBN[12]='X';
		cout<<ISBN;
	}
	return 0;
}
