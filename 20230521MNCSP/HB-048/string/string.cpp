#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(s[i]=='{'){
			int l=i,r,j,r1;
			for(r=i;s[r]!='}';r++);
			r1=r;
			l++,r--;
			while(s[l]==' ')	l++;
			while(s[r]==' ')	r--;
			string strnum=s.substr(l,r-l+1);
			int num;
			for(j=0;j<strnum.size();j++)
				num=num*10+int(strnum[j]-'0');
			int hex[10];
			for(j=1;num;j++){
				hex[j]=num%16;
				num/=16;
			}
			cout<<"0x";
			for(j--;j>=1;j--)
				if(hex[j]<10)	cout<<hex[j];
				else	cout<<char(hex[j]-10+'A');
			i=r1;
		}else{
			cout<<s[i];
		}
	}
	return 0;
}
