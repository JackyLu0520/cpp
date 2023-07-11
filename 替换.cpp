#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3;
int num=0;
int main(){
	getline(cin,s1);
	getline(cin,s2);
	getline(cin,s3);
	while(s1.find(s2)!=string::npos){
		num++;
		s1.replace(s1.find(s2),s2.size(),s3);
	}
	cout<<num<<endl<<s1;
	return 0;
}
