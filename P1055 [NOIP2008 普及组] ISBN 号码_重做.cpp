#include<bits/stdc++.h>
using namespace std;
int n;
char m[12]="0123456789X",s[14],isbn[10];
int main(){
	cin>>s;
	sscanf(s,"%c-%c%c%c-%c%c%c%c%c-%c",
		&isbn[0],&isbn[1],&isbn[2],&isbn[3],&isbn[4],
		&isbn[5],&isbn[6],&isbn[7],&isbn[8],&isbn[9]);
	if(isbn[9]=='X')	isbn[9]='0'+10;
	for(int i=0;i<9;i++)
		n+=(isbn[i]-'0')*(i+1);
	n%=11;
	if(n==isbn[9]-'0')
		cout<<"Right";
	else{
		s[12]=m[n];
		cout<<s;
	}
	return 0;
}
