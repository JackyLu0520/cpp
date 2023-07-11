#include<iostream>
#include<string>
using namespace std;
int main(){
	string a,b;
	int i,num=0,as,bs,sn;
	getline(cin,a);as=a.size();
	getline(cin,b);bs=b.size();
	for(i=0;i<as;i++)	if(a[i]>='A'&&a[i]<='Z')	a[i]+=32;
	for(i=0;i<bs;i++)	if(b[i]>='A'&&b[i]<='Z')	b[i]+=32;
	b=" "+b+" ";
	for(i=1;i<=bs-as+1;i++)
		if(b[i-1]==' '&&b[i+as]==' '){
			if(b.substr(i,as)==a){
				num++;
				if(num==1)	sn=i-1;
			}
		}
	if(num)	cout<<num<<' '<<sn;
	else	cout<<-1;
	return 0;
}
